#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
struct log//�ṹ�� 
{
	char timestamp[100];
	char clientip[100];
	char request[300];
	char status[50];
	char size[100];
};
void tihaoshuru(int jishu,struct log *jiegouti,FILE*fp); //������ 
float dehanshu(int jishu,struct log *jietouti);//�ڶ��� 
int dshanshu(int jishu,int *sta_p,int *stt_p,struct log *jiegouti);//������ 
void dsihanshu(int jishu,struct log *jiegouti,char *ip,int *ipmax);//������ 
int rizhicount(int jishu,struct log *jiegouti);//������ 
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
		if(p==NULL)//����500��  ÿ�ν�����  jishu++  һ��500�� ���һ�κ� ��Ϊ��NULL �����ǿ� break�� 
		{
			break;
		}
		jishu++;
//		printf("%s",jieshou);
	// ���� jieshou�����ݵ� str 
		for(j=0;j<5;j++)
		{ 
			if(j==0)
			{
				strcpy(cstr,strtok(jieshou,","));    //�ָ��һ�� ��Ȼ��ѵ�һ�εĶ�����cstr 	
			}
			else
			{
				strcpy(cstr,strtok(NULL,","));
			}
			switch(j)
			{
				
				case 0:		
					strcpy(jiegouti[i].timestamp,cstr); //��cstr�Ķ��� ���ṹ���timestamp 
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
{	struct log jiegouti[1000];//�����ṹ�� 
	char str[300];//��ȡ�ļ�ÿ�е��ַ��� 
	char cstr[300];//��Ϊ���ָܷ���ַ��� 
	char jieshou[1000];//���� 
	int jishu; //���ж����д��� 
	//�������� ȫ���� 
	FILE*fl;//����ָ�� 
	system("color 7D");//��ɫ���� 
	fl=fopen("3_elasticsearch.log","r");//��ȡ�ļ� 
	jishu=shuru(fl,sizeof(jieshou),jieshou,jiegouti);//jishu����500    ��һ���ָ�� 
	int tihao;FILE* fp;
		fp=fopen("my.txt","w+");// w+�Ǵ��ı���ʽ ��д  wֻ��д 
	tihaoshuru(jishu,jiegouti,fp);	
	return 0;
}
void tihaoshuru(int jishu,struct log *jiegouti,FILE*fp)// ��� jishu=����  ���нṹ�� 
{	
	int k; int i;
	while(1)
	{	
	printf("************************************\n");	
	printf("1.����ʺϵĽṹ�壬����־�ļ��е����ݶ���ṹ�����\n");
	printf("2.������־�ļ���GET��������ʽ��ռ��\n");
	printf("3.��״̬����з�����ͳ�ƣ�������Ӧ״̬������״̬�ı���\n");
	printf("4.�����ͻ����������Ŀͻ�IP��ַ����ͳ������ʴ���\n");
	printf("5.������־���Ƿ����״̬��ֵ ����300-399��Χ��������ͳ����־��Ŀ\n");
	printf("6.�û�����ʱ��Σ����Ҹ�ʱ����ڷ��ʼ�¼����������ļ���\n");
	printf("7.��(2)~(5)������浽�ļ��У����������´γ�������ʱ��ȡ����ʾ��*��\n");
	printf("8.�Զ��幦�ܣ������û���Ҫ��size��Χ\n");
	printf("�����빦�ܺ�\n");
	printf("����0���˳�\n");
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
				printf("�ڶ���:GETռ��Ϊ%.2f%%\n",dierti*100);			
				fprintf(fp,"�ڶ���:GETռ��Ϊ%.2f%%\n",dierti*100);	
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
					printf("%d��%d��,ռ��Ϊ%.2f%%\n",sta[i],stt[i],(float)stt[i]/jishu*100);
					fprintf(fp,"%d��%d��,ռ��Ϊ%.2f%%\n",sta[i],stt[i],(float)stt[i]/jishu*100);
				}
				break;
			}
			case 4:
			{				
				int ipcnt;
				char ip[50]={0};
				char *ip_p=ip;
				int *ipc_p=&ipcnt;//ָ��ָ�����ipcnt�ĵ�ַ 
				dsihanshu(jishu,jiegouti,ip_p,ipc_p);	
				printf("IP%s���ֵĴ������Ϊ%d\n",ip_p,ipcnt);	
				fprintf(fp,"IP%s���ֵĴ������Ϊ%d\n",ip_p,ipcnt);	
				break;
			}
			case 5:
			{
				int rzsm= rizhicount(jishu,jiegouti);
				printf("��Χ��300-399֮����־��ĿΪ%d��\n",rzsm);
				fprintf(fp,"��Χ��300-399֮����־��ĿΪ%d��\n",rzsm);
				break; 
			}
			case 6:
			{
				double shijianduan1=0 ;double shijianduan2=0; //2��ʱ���  �ɴ�30λ��
					printf("������ʱ���\n");
				scanf("%lf",&shijianduan1);// ��һ��ʱ��� 
				scanf("%lf",&shijianduan2); // �ڶ���ʱ��� 
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
				printf("�����������size��Χ\n") ;
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
//�ڶ��� �ڶ��� �ڶ��� �ڶ��� �ڶ��� �ڶ��� �ڶ��� �ڶ��� �ڶ��� �ڶ��� 
float dehanshu(int jishu,struct log *jiegouti)
{
	char *getzz;
	float count2=0;
	int k; 
	for(k=0;k<jishu;k++)
	{	
		getzz=strstr(jiegouti[k].request,"GET");//strstr������  �����ַ����е����ַ��� 
		if(getzz!=NULL)
		{
			count2++;
		}
	}
	float rateG=(count2/jishu)*1.0;
	return rateG;
}
//������ ������ ������ ������ ������ ������ ������ ������ ������ ������ ������ ������ 
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
	for(i=0;i<jishu;i++) //��ÿ��status����ѭ������ (��500) 
	{	
		char cstr[20];
		int lb=1;
		int csta;
		strcpy(cstr,strtok(stafb[i]," "));
		strcpy(cstr,strtok(NULL," ")); //�ո�ָ� 
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
//������ ������ ������ ������ ������ ������ ������ ������ ������ ������ ������ ������ ������ 
void dsihanshu(int jishu,struct log *jiegouti,char *ip,int *ipmax)
{
	char IP[120][40]={0}; //IP 50�Ƕ����� 40 ��IP���� 
	int IPcount[100]={0};//ÿ��IP�ĸ���
	int yesorno=0;
	int j=0,i;
	int kk;
	for(i=0;i<jishu;i++) //��ÿ��IP����ѭ������ (��500) 
	{	
		int lb=1; 
		for(kk=0;kk<j;kk++)
		{		//IPkk ��ʼ����0�����к�ԭ�ļ��е�IP���бȽ� �������� ��ô���ṹ���IP�滻��IPkk�У�  jj+1��  
			yesorno=strcmp(jiegouti[i].clientip,IP[kk]);					
			if(yesorno==0)	
			{
				IPcount[kk]++;
				lb=0;
				break;
			}
//jiegouti IP��log�����е�IP  IPkk�Ǽ�¼��(��ͬ�����)IP  ipKK�ܹ���¼����IP 
		}
		if(lb==1)
		{						
			strcpy(IP[j],jiegouti[i].clientip);
			IPcount[j]++;
			j++;//J��IP���� 
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

//������ ������ ������ ������ ������ ������ ������ ������ ������ ������ ������ ������ ������ 
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
//	//������ ������ ������ ������ ������ ������ ������ ������ 
double sixti(int jishu,struct log *jiegouti,int *jiaobiao,double shijianduan1,double shijianduan2)
{	
		double timestamp2[500]={0};
		char *ste3;
		int i;
		for(i=0;i<jishu;i++)  //���ѭ����������  �ָ�ʱ��� ���Ұ�ʱ���char�͸�Ϊ double��   ����¼������timestamp2 
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
				if(timestamp2[i]<=shijianduan2)//��Щʱ����� ��Χ�� 
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
		int jk=0;  //jkΪ�������鷶Χ��size���� 
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

