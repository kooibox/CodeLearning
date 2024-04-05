#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
struct log//结构体 
{
	char timestamp[100];
	char clientip[100];
	char request[300];
	char status[50];
	char size[100];
};
void tihaoshuru(int jishu,struct log *jiegouti,FILE*fp); //题号输出 
float dehanshu(int jishu,struct log *jietouti);//第二题 
int dshanshu(int jishu,int *sta_p,int *stt_p,struct log *jiegouti);//第三题 
void dsihanshu(int jishu,struct log *jiegouti,char *ip,int *ipmax);//第四题 
int rizhicount(int jishu,struct log *jiegouti);//第五题 
double sixti(int jishu,struct log *jiegouti,int *jiaobiao,double shijianduan1,double shijianduan2);
int dibati(int jishu,struct log *jiegouti,int flsize[],int fw1,int fw2);
int shuru(FILE *fl,int lg,char *jieshou,struct log *jiegouti)
{		
	int jishu=0;
	char cstr[300];
	int i,j;
	char *p;
	for(i=0;;i++)
	{	
		p=fgets(jieshou,lg,fl);
		if(p==NULL)//接受500次  每次接受完  jishu++  一共500次 最后一次后 因为是NULL 所以是空 break了 
		{
			break;
		}
		jishu++;
//		printf("%s",jieshou);
	// 复制 jieshou的内容到 str 
		for(j=0;j<5;j++)
		{ 
			if(j==0)
			{
				strcpy(cstr,strtok(jieshou,","));    //分割第一段 ，然后把第一段的东西给cstr 	
			}
			else
			{
				strcpy(cstr,strtok(NULL,","));
			}
			switch(j)
			{
				
				case 0:		
					strcpy(jiegouti[i].timestamp,cstr); //把cstr的东西 给结构体的timestamp 
				break;
				case 1:
					strcpy(jiegouti[i].clientip,cstr);
				break;
				case 2:
					strcpy(jiegouti[i].request,cstr);
				break;
				case 3:
					strcpy(jiegouti[i].status,cstr);
				break;
				case 4:
					strcpy(jiegouti[i].size,cstr);
				break;
			}
		}
	}
	return jishu;	
}
int main()
{	struct log jiegouti[1000];//创建结构体 
	char str[300];//读取文件每行的字符串 
	char cstr[300];//作为接受分割的字符串 
	char jieshou[1000];//接受 
	int jishu; //共有多少行代码 
	//接受内容 全部的 
	FILE*fl;//建立指针 
	system("color 7D");//颜色代码 
	fl=fopen("3_elasticsearch.log","r");//读取文件 
	jishu=shuru(fl,sizeof(jieshou),jieshou,jiegouti);//jishu等于500    第一个分割函数 
	int tihao;FILE* fp;
		fp=fopen("my.txt","w+");// w+是纯文本方式 读写  w只能写 
	tihaoshuru(jishu,jiegouti,fp);	
	return 0;
}
void tihaoshuru(int jishu,struct log *jiegouti,FILE*fp)// 题号 jishu=行数  还有结构体 
{	
	int k; int i;
	while(1)
	{	
	printf("************************************\n");	
	printf("1.设计适合的结构体，将日志文件中的数据读入结构体变量\n");
	printf("2.计算日志文件中GET类型请求方式的占比\n");
	printf("3.对状态域进行分析与统计，计算响应状态域所有状态的比率\n");
	printf("4.分析客户端请求最多的客户IP地址，并统计其访问次数\n");
	printf("5.分析日志中是否包含状态域值 属于300-399范围，若存在统计日志数目\n");
	printf("6.用户输入时间段，查找该时间段内访问记录，并输出到文件中\n");
	printf("7.将(2)~(5)结果保存到文件中，并可以在下次程序运行时读取并显示（*）\n");
	printf("8.自定义功能（调查用户需要的size范围\n");
	printf("请输入功能号\n");
	printf("输入0则退出\n");
	printf("************************************\n");
		int tihao;
		scanf("%d",&tihao);
		if(tihao==0)
		{	fclose(fp);
			break;
		}
		switch(tihao)
		{	
			case 2:
			{	
				float dierti;								
				dierti=dehanshu(jishu,jiegouti);
				printf("第二题:GET占比为%.2f%%\n",dierti*100);			
				fprintf(fp,"第二题:GET占比为%.2f%%\n",dierti*100);	
				break;
			}
			case 3:
			{	
				int sta[20]={0};
				int stt[20]={0};
				int *sta_p=sta;
				int *stt_p=stt;
				int cnt=0;	
				cnt=dshanshu(jishu,sta,stt,jiegouti);
				for (i=0;i<cnt;i++)
				{
					printf("%d有%d个,占比为%.2f%%\n",sta[i],stt[i],(float)stt[i]/jishu*100);
					fprintf(fp,"%d有%d个,占比为%.2f%%\n",sta[i],stt[i],(float)stt[i]/jishu*100);
				}
				break;
			}
			case 4:
			{				
				int ipcnt;
				char ip[50]={0};
				char *ip_p=ip;
				int *ipc_p=&ipcnt;//指针指向饿了ipcnt的地址 
				dsihanshu(jishu,jiegouti,ip_p,ipc_p);	
				printf("IP%s出现的次数最多为%d\n",ip_p,ipcnt);	
				fprintf(fp,"IP%s出现的次数最多为%d\n",ip_p,ipcnt);	
				break;
			}
			case 5:
			{
				int rzsm= rizhicount(jishu,jiegouti);
				printf("范围在300-399之间日志数目为%d个\n",rzsm);
				fprintf(fp,"范围在300-399之间日志数目为%d个\n",rzsm);
				break; 
			}
			case 6:
			{
				double shijianduan1=0 ;double shijianduan2=0; //2个时间段  可存30位数
					printf("请输入时间段\n");
				scanf("%lf",&shijianduan1);// 第一个时间段 
				scanf("%lf",&shijianduan2); // 第二个时间段 
			int *pjb;	int jiaobiao[100]={0};
			pjb=jiaobiao; int i; int f;
			double geshu=sixti(jishu,jiegouti,pjb,shijianduan1,shijianduan2);
			for(i=0;i<geshu;i++)
			{	f=jiaobiao[i];
					printf("%s\n",jiegouti[f].clientip);
					printf("%s\n",jiegouti[f].request);
					printf("%s\n",jiegouti[f].status);
					printf("%s\n",jiegouti[f].size);
				
					fprintf(fp,"%s\n",jiegouti[f].clientip);
					fprintf(fp,"%s\n",jiegouti[f].request);
					fprintf(fp,"%s\n",jiegouti[f].status);
					fprintf(fp,"%s\n",jiegouti[f].size);
				
			}
		
				break;
			}
			case 8:
			{	
				int i;int flsize[200];
				printf("请输入所需的size范围\n") ;
				int fw1; int fw2;
				FILE*fpv;
				fpv=fopen("other.txt","w+");
				scanf("%d",&fw1); scanf("%d",&fw2);
				int yy=dibati(jishu,jiegouti,flsize,fw1,fw2);
			for(i=0;i<yy;i++)
			{		
					printf("%s\n",jiegouti[flsize[i]].clientip);
					printf("%s\n",jiegouti[flsize[i]].request);
					printf("%s\n",jiegouti[flsize[i]].status);
					printf("%s\n",jiegouti[flsize[i]].size);
					
					fprintf(fpv,"%s\n",jiegouti[flsize[i]].clientip);
					fprintf(fpv,"%s\n",jiegouti[flsize[i]].request);
					fprintf(fpv,"%s\n",jiegouti[flsize[i]].status);
					fprintf(fpv,"%s\n",jiegouti[flsize[i]].size);
				
			}
				break;
			}
		}
	}	
}
//第二题 第二题 第二题 第二题 第二题 第二题 第二题 第二题 第二题 第二题 
float dehanshu(int jishu,struct log *jiegouti)
{
	char *getzz;
	float count2=0;
	int k; 
	for(k=0;k<jishu;k++)
	{	
		getzz=strstr(jiegouti[k].request,"GET");//strstr作用是  查找字符串中的子字符串 
		if(getzz!=NULL)
		{
			count2++;
		}
	}
	float rateG=(count2/jishu)*1.0;
	return rateG;
}
//第三题 第三题 第三题 第三题 第三题 第三题 第三题 第三题 第三题 第三题 第三题 第三题 
int dshanshu(int jishu,int *sta_p,int *stt_p,struct log *jiegouti)
{
//	char sta[100][20]={0};
	int j=0,i=0;
	int kk=0;  
	char stafb[500][30];
	for(i=0;i<jishu;i++)
	{
		strcpy(stafb[i],jiegouti[i].status);
	}
	for(i=0;i<jishu;i++) //把每个status都能循环出来 (共500) 
	{	
		char cstr[20];
		int lb=1;
		int csta;
		strcpy(cstr,strtok(stafb[i]," "));
		strcpy(cstr,strtok(NULL," ")); //空格分割 
		csta=atoi(cstr);
		for(kk=0;kk<j;kk++)
		{			
			if(csta==sta_p[kk])	
			{
				stt_p[kk]++;
				lb=0;
				break;
			}				
		}
		if(lb==1)
		{
			sta_p[j]=csta;
			stt_p[j]++;
			j++;
		}
	}
	return j;
}
//第四题 第四题 第四题 第四题 第四题 第四题 第四题 第四题 第四题 第四题 第四题 第四题 第四题 
void dsihanshu(int jishu,struct log *jiegouti,char *ip,int *ipmax)
{
	char IP[120][40]={0}; //IP 50是多少种 40 是IP长度 
	int IPcount[100]={0};//每种IP的个数
	int yesorno=0;
	int j=0,i;
	int kk;
	for(i=0;i<jishu;i++) //把每个IP都能循环出来 (共500) 
	{	
		int lb=1; 
		for(kk=0;kk<j;kk++)
		{		//IPkk 初始化是0，进行和原文件中的IP进行比较 如果不相等 那么将结构体的IP替换给IPkk中，  jj+1，  
			yesorno=strcmp(jiegouti[i].clientip,IP[kk]);					
			if(yesorno==0)	
			{
				IPcount[kk]++;
				lb=0;
				break;
			}
//jiegouti IP是log的所有的IP  IPkk是记录的(不同种类的)IP  ipKK能够记录几种IP 
		}
		if(lb==1)
		{						
			strcpy(IP[j],jiegouti[i].clientip);
			IPcount[j]++;
			j++;//J是IP个数 
		}
	}
	int maxx=IPcount[0];
	int max=0;
	for(i=0;i<j;i++)
	{
		if(maxx<IPcount[i])
		{
			maxx=IPcount[i];
			max=i;
		}
	}
	
	*ipmax=IPcount[max];
	strcpy(ip,IP[max]);	
}

//第五题 第五题 第五题 第五题 第五题 第五题 第五题 第五题 第五题 第五题 第五题 第五题 第五题 
int rizhicount(int jishu,struct log *jiegouti)
{
		int yesorno=0; int kk;
	char	sta2[100][20]={0}; int j=0; int i=0;
	int stacount2[100]={0};
		int ztm[j]; int rzsm=0;
		char zfc[30];
		for(i=0;i<jishu;i++)
		{	strcpy(zfc,jiegouti[i].status);
			char *ste=strtok(zfc,":");
			ste=strtok(NULL," ");
			ztm[i]=atoi(ste);
 			
			if(ztm[i]<=399&&ztm[i]>=300)
			{
				rzsm++;
			}
		}
		return rzsm;
	}
//	//第六题 第六题 第六题 第六题 第六题 第六题 第六题 第六题 
double sixti(int jishu,struct log *jiegouti,int *jiaobiao,double shijianduan1,double shijianduan2)
{	
		double timestamp2[500]={0};
		char *ste3;
		int i;
		for(i=0;i<jishu;i++)  //这个循环的作用是  分割时间戳 并且把时间戳char型改为 double型   并记录数据于timestamp2 
		{
			ste3=strtok(jiegouti[i].timestamp,": ");
			ste3=strtok(NULL," ");
		timestamp2[i]=atoi(ste3);
		}
		int geshu=0; int k=0;
		for(i=0;i<jishu;i++)
		{
			if(shijianduan1<timestamp2[i])
			{
				if(timestamp2[i]<=shijianduan2)//这些时间戳在 范围内 
				{	
					jiaobiao[k]=i;
					k++;geshu++;
				}
			}
		
		}
		return geshu;
}
int dibati(int jishu,struct log *jiegouti,int flsize[],int fw1,int fw2)
{
	int i;	char sizefb[100];
		char *psize;
		int jk=0;  //jk为符合所查范围的size个数 
		 int sizedx[500];  int ss;
		for(i=0;i<jishu;i++)
		{	strcpy(sizefb,jiegouti[i].size);
			psize=strtok(sizefb,": ");
			psize=strtok(NULL,"}");
			sizedx[i]=atoi(psize);
			if(fw1>fw2)
			{
					if(sizedx[i]<=fw1&&sizedx[i]>=fw2)
				{	
				flsize[jk] =i;
					jk++;
				}
			}
			if(fw1<=fw2)
			{
				if(sizedx[i]>=fw1&&sizedx[i]<=fw2)
				{	
					flsize[jk] =i;
					jk++;
				}
			}

		}	
	return jk;
}

