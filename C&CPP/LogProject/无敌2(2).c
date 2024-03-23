#include <string.h>
#include <stdio.h>

/* 
  ����ÿ����־�ṹ��,Ԫ�ؿռ䲻������ֺϲ�������,��������Խ��
*/ 
struct log_Item//(����һ���ṹ�������洢��־�е�����)
{
    char [10];//����ʽ
    char Client_IP[20];//�ͻ���IP
    char Protocol[15];//Э��
    char Time[25];//ʱ��yyyy-mm-dd hh:mm:ss
    char URL[150];//���ʵ�ַ
    char Resource[150];//����ҳ�� 
    char Content[250];//�����б� 
    char Status[10];//״̬��
    char Client_Browser[400];//�������Ϣ
};

/* 
  ���ڸ�ֵ��־�ṹ��ĵ�i��Ԫ��Ϊ�ַ��� src  
*/ 
void construct_Log(struct log_Item * item, int i, char *src)
{
    switch(i){
    case 0: strcpy(item->Method, src);break;//(1->������ָ��ṹ�������ݵ�ָ�룬����ȡ������)
    case 1: strcpy(item->Client_IP, src);break;//(2ȡ��item��ָ��Ľṹ���а����������� Client_IP) 
    case 2: strcpy(item->Protocol, src);break;//(3����strcpy������src�����е��ַ������Ƶ�item->Client_IP��) 
    case 3: strcpy(item->Time, src);break;
    case 4: strcpy(item->URL, src);break;
    case 5: strcpy(item->Resource, src);break;
    case 6: strcpy(item->Content, src);break;
    case 7: strcpy(item->Status, src);break;
    case 8: strcpy(item->Client_Browser, src);break;
    default : ;//����ִ��ʱִ�� 
    }
}

/* 
  ��ӡ��־�ṹ�������ȫ��Ԫ��
*/ 
void Print_logData(struct log_Item your[],int ietm_num)//���ú��� Print_logData���ṹ�������ӡ 
{
    int i;
    for(i = 0;i<ietm_num;i++)
    printf("%d==%s %s %s %s %s %s %s %s %s\n",
    i,your[i].Method,your[i].Client_IP,your[i].Protocol,your[i].Time,your[i].URL,
    your[i].Resource,your[i].Content,your[i].Status,your[i].Client_Browser);    
}

/* 
  ����־�ļ�filename����ֵ���ṹ������your
  ������־��Ŀ��num 
*/ 
int Read_logFile(char *filename,struct log_Item *your)
{
    FILE *fp = NULL;
    char str[855];     
    const char s[2] = "|"; 
    char *token; 
    int i;
    fp = fopen(filename, "r");
    int num = 0;
    
    while(fgets(str, 855, fp) != NULL)
    {
        i = 0;
        token = strtok(str, s);
        construct_Log(&your[num],i, token);
        i++;
        while (token != NULL){
            token = strtok(NULL, s);
            construct_Log(&your[num],i, token);           
            i++;
        }
        num ++;     
    };  
    fclose(fp); 
    return num;
}

 
 // ͳ����־�ṹ������MethodԪ��[GET]�ĸ��� 
 
int static_get(struct log_Item your[], int log_item)//���Զ��庯��static_getͳ��[GET]���� 
{
    int get_num = 0;
    int i;
    for (i = 0; i < log_item; i++)
    {   
        if ( strcmp( your[i].Method, "[GET]") == 0 ) //�ַ������
            get_num ++;
    }
    return get_num;//���õ���[GET]������������������ 
}
void static_wudi(int *chder,char *Status,int *a)//�Զ���һ������static_wudi�����Ƚ�������״̬�������״̬�� 
{
	int i=0;
	int b=(*(Status+1)-'0')*100+(*(Status+2)-'0')*10+(*(Status+3)-'0')*1;//��Status�е����ݸ�Ϊint�� 
	for(i=0;i<57;i++)//����һ��forѭ��������״̬����������״̬��һһ���бȶ� 
	{
	if(b==chder[i])
	a[i]++;//����õĽ��������һ������������ͳ�Ƹ���״̬����ֵĴ��� 
	}
}
int wowudi(char*hang,char*shou)//����һ������wowudi��hang����ÿ�е�������shou�������� 
{
	int i=0;
	char*poi=strstr(hang,"password=");//���ú���strstr�Ա�ÿ�е��������Ƿ��С�password=�� 
	if(poi==NULL)
	{
		*shou='\0';
		return 0;
	}
	poi+=9;//�������shou�������ݣ����ܵ�Ϊpoi+=9�����ݼ���password=���ĳ��ȣ�����password=���濪ʼ��¼���� 
	while(*poi!=']'&&*poi!='&')//��whileѭ�������ݴ���shou�� 
	{
		shou[i]=*poi;
		i++ ;
		poi++ ;
	}
	shou[i] = '\0' ;
	return 1;
}
int niwudi(char*hang,char*shou)//ͬ�� ������һ������niwudi ��ʵ���뺯��wowudiͬ���Ĺ���
{   
	int i=0;
	char*poi=strstr(hang,"passwd=");
	if(poi==NULL)
	{
		*shou='\0';
		return 0;
	}
	poi+=7;
	while(*poi!=']'&&*poi!='&')
	{
		shou[i]=*poi;
		i++ ;
		poi++ ;
	}
	shou[i] = '\0' ;
	return 1;
}
int time(struct log_Item your[])//ʱ�� 
{     
 int log_num;
        log_num = Read_logFile("1access.log",your); 
  FILE *fp;
  fp=fopen("access2.log","w");
  int i;
  int a,b;
  getchar(); 
  char s_time[255];
  char e_time[255];
  printf("�����뿪ʼʱ�� ([yyyy-mm-dd hh:mm:ss]): ");
  gets(s_time);
  printf("���������ʱ�� ([yyyy-mm-dd hh:mm:ss]): ");
  gets(e_time);
  printf("�ڴ������������\n");
  for(i=0;i<log_num;i++){
  a=strcmp(s_time,your[i].Time);
  b=strcmp(e_time,your[i].Time);
  if(a<=0&&0<=b)
  {
  printf("%s,%s,%s,%s,%s,%s,%s,%s,%s\n",your[i].Method,your[i].Client_IP,your[i].Protocol,your[i].Time,your[i].URL, your[i].Resource,your[i].Content,your[i].Status,your[i].Client_Browser);
  fprintf(fp,"%s,%s,%s,%s,%s,%s,%s,%s,%s\n",your[i].Method,your[i].Client_IP,your[i].Protocol,your[i].Time,your[i].URL, your[i].Resource,your[i].Content,your[i].Status,your[i].Client_Browser);
  }

  }
   fclose(fp);
   return 0;
}
int main()
{
	struct log_Item your[1000];
	int log_num;
	log_num = Read_logFile("1access.log", your);
	while (1)//�����棺��Ŀ¼ 
  {
  printf("----------------------��־����---------------------\n");
  printf("1=���GET������ռ����\n");
  printf("2=����������״̬��ı���\n");
  printf("3=�����������Ŀͻ�IP\n");
  printf("4=�������������Գ��ִ���\n");
  printf("5=����ʱ��β�����������ڵ���־���ļ�\n");
  printf("6=�˳�����\n");
  printf("����������ѡ��:\n");
   int n; scanf("%d", &n);
  if (n>7 || n<1)
   {
   printf("��Чָ��\n");
   }
   if(n == 1)
    {
    int get_num;
   // Print_logData(your,log_num);//������е��������� 
    get_num = static_get(your,log_num);
    printf("\n[GET] number =%d  ""GET����������ռ�ı���:%.2lf%%\n",get_num,(float)get_num/log_num*100);
	}
	 if(n == 2)
	 {
	 int i=0,j=0;
	int chder[57]={100,101,102,200,201,202,203,204,205,206,207,300,301,302,303,304,305,306,307,400,401,402,403,404,405,406,407,408,409,410,411,412,413,414,415,416,417,418,421,422,423,424,425,426,449,451,500,501,502,503,504,505,506,507,509,510,600};
	int a[56]={0};
	for(i=0;i<=log_num;i++)
	{
	static_wudi(chder,your[i].Status,a);
	}
	for(i=0;i<56;i++)
	{
		if(a[i]==0)
		{
			continue;
		} 
		printf("״̬��Ϊ%d�����ʴ���Ϊ%d����ռ����Ϊ%.2lf%%\n", chder[i], a[i], (float)a[i]/log_num*100);
	}	
	 }
	 if(n == 3)
	 {
	 	//  �����������Ŀͻ�IP��ַ����ͳ������ʴ���
	int max = 0;	//�����洢��������
	int index = 0;//�����洢�ִ��������Ǹ��ַ���������
	int i=0;
	int j=0;
	char* fstr;//������ʱָ����������Ҫ����������Ԫ�ؽ��бȽϵ��ַ���
	int temp = 0;	//�����洢*fstr�ַ������ֵĴ���
	for(i=0; i<log_num; i++)
	{
		fstr = your[i].Client_IP;
		for(j=0; j<=i; j++)
		{
			if(strcmp(fstr, your[j].Client_IP) == 0)
				temp++;
		}
			if(temp > max)
			{
			max = temp;
			index = i;
			}
			temp = 0;
	}
	printf("���ִ������Ŀͻ�ip��ַ��%s ���ʴ��� %d ��\n", your[index].Client_IP,max);
     }
    
if(n == 4)
{
	int index=0;
    char mama[600][100];
    int i=0;
    int j=0;
    int g=0;
    int h;
    int t=0;
    char *fst;
    int m = 0;	//�����洢��������
	int ind = 0;	//�����洢�ִ��������Ǹ��ַ���������
for(i=0,j=0;i<log_num; i++) {
		h=wowudi(your[i].Content,mama[j]) ;
		if(h!= 0) {
			g++ ;
			j++	;
		}
	}
	for(i=0;i<log_num;i++) {
		h= niwudi(your[i].Content,mama[j]) ;
		if(h!= 0) {
			g++ ;
			j++	;
		}
	}
for(i=0; i<g; i++){
		fst = mama[i];
		for(j=0; j<=i; j++){
			if(strcmp(fst, mama[j]) == 0)
				t++;
			}
			if(t > m){
			m = t;
			index = i;
			}
			t= 0;
	}
	printf("���ִ���������룺%s ���ʴ��� %d ��\n", mama[ind],m);
}
    
if(n==5)
  {
   time(your);
    return (0);
  }
  }
}
