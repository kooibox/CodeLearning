#include<stdio.h>
#include<string.h>
struct log{
	char time[100];
	char ip[100];
	char request[100];
	char status[50];
	char size[20];
};

int sign2;

void construct_log(struct log *item,int i,char *src)
{
	switch(i)
	{
		case 0:strcpy(item->time,src);break;
		case 1:strcpy(item->ip,src);break;
		case 2:strcpy(item->request,src);break;
		case 3:strcpy(item->status,src);break;
		case 4:strcpy(item->size,src);break;
		default:;
	}
}

int read(char *file,struct log *my)
{
	FILE *fp=NULL;
	char str[669];
	const char s[2]=",";
	char *token;
	fp=fopen(file,"r");
	if(fp==NULL)
		printf("文件没有被打开"); 
	int i=0;
	while(fgets(str,669,fp)){
		int j=0;
		
		token=strtok(str,s);
		construct_log(&my[i],j,token);
		j++;
		while(token!=NULL)
		{
			token=strtok(NULL,s);
			construct_log(&my[i],j,token);
			j++;
		}
	
		i++;
	}
	fclose(fp);
	//printf("%d\n\n",i);
	return i;
}

int datascale(struct log *item,int m)  // 第二问 
{
	int num=0,j;
	for(j=0;j<m;j++)
	{
		num+=strstr(item[j].request,"GET")!=NULL;
	}
	float cd=(float)num/m*100;
	if(!sign2)
	{
		FILE *fp;
		fp=fopen("address.txt","a");
		fprintf(fp,"%.2f%%\n",cd);
		fclose(fp);
		sign2=1;
	}
	else
	{
		printf("%.2f%%\n",cd);
		sign2=0;
	}
	return 0;
}
int main()
{
	int num,sum;
	struct log my[1000]; 
	char file[]="aim.log";
	sum=read(file,my);
	datascale(my,sum);
	datascale(my,sum);
	return 0;
} 
