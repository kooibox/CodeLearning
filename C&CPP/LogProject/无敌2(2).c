#include <string.h>
#include <stdio.h>

/* 
  定义每条日志结构体,元素空间不够会出现合并的问题,导致数组越界
*/ 
struct log_Item//(定义一个结构体用来存储日志中的数据)
{
    char Method[10];//请求方式
    char Client_IP[20];//客户端IP
    char Protocol[15];//协议
    char Time[25];//时间yyyy-mm-dd hh:mm:ss
    char URL[150];//访问地址
    char Resource[150];//访问页面 
    char Content[250];//参数列表 
    char Status[10];//状态码
    char Client_Browser[400];//浏览器信息
};

/* 
  用于赋值日志结构体的第i项元素为字符串 src  
*/ 
void construct_Log(struct log_Item * item, int i, char *src)
{
    switch(i){
    case 0: strcpy(item->Method, src);break;//(1->是用于指向结构体子数据的指针，用来取子数据)
    case 1: strcpy(item->Client_IP, src);break;//(2取出item所指向的结构体中包含的数据项 Client_IP) 
    case 2: strcpy(item->Protocol, src);break;//(3运用strcpy函数将src数组中的字符串复制到item->Client_IP中) 
    case 3: strcpy(item->Time, src);break;
    case 4: strcpy(item->URL, src);break;
    case 5: strcpy(item->Resource, src);break;
    case 6: strcpy(item->Content, src);break;
    case 7: strcpy(item->Status, src);break;
    case 8: strcpy(item->Client_Browser, src);break;
    default : ;//当不执行时执行 
    }
}

/* 
  打印日志结构体数组的全体元素
*/ 
void Print_logData(struct log_Item your[],int ietm_num)//调用函数 Print_logData将结构体数组打印 
{
    int i;
    for(i = 0;i<ietm_num;i++)
    printf("%d==%s %s %s %s %s %s %s %s %s\n",
    i,your[i].Method,your[i].Client_IP,your[i].Protocol,your[i].Time,your[i].URL,
    your[i].Resource,your[i].Content,your[i].Status,your[i].Client_Browser);    
}

/* 
  读日志文件filename并赋值到结构体数组your
  返回日志条目数num 
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

 
 // 统计日志结构体数组Method元素[GET]的个数 
 
int static_get(struct log_Item your[], int log_item)//用自定义函数static_get统计[GET]个数 
{
    int get_num = 0;
    int i;
    for (i = 0; i < log_item; i++)
    {   
        if ( strcmp( your[i].Method, "[GET]") == 0 ) //字符串相等
            get_num ++;
    }
    return get_num;//将得到的[GET]的数量返还给主函数 
}
void static_wudi(int *chder,char *Status,int *a)//自定义一个函数static_wudi用来比较数组中状态码和所有状态码 
{
	int i=0;
	int b=(*(Status+1)-'0')*100+(*(Status+2)-'0')*10+(*(Status+3)-'0')*1;//把Status中的内容改为int型 
	for(i=0;i<57;i++)//运用一个for循环将所有状态码与数组钟状态码一一进行比对 
	{
	if(b==chder[i])
	a[i]++;//将获得的结果存在另一个数组中用以统计个个状态码出现的次数 
	}
}
int wowudi(char*hang,char*shou)//定义一个函数wowudi用hang代表每行的数据用shou接收数据 
{
	int i=0;
	char*poi=strstr(hang,"password=");//利用函数strstr对比每行的数据中是否有“password=” 
	if(poi==NULL)
	{
		*shou='\0';
		return 0;
	}
	poi+=9;//如果有用shou接受数据，接受的为poi+=9的数据及“password=”的长度，即从password=后面开始纪录数据 
	while(*poi!=']'&&*poi!='&')//用while循环将数据存入shou中 
	{
		shou[i]=*poi;
		i++ ;
		poi++ ;
	}
	shou[i] = '\0' ;
	return 1;
}
int niwudi(char*hang,char*shou)//同理 ：定义一个函数niwudi 用实现与函数wowudi同样的功能
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
int time(struct log_Item your[])//时间 
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
  printf("请输入开始时间 ([yyyy-mm-dd hh:mm:ss]): ");
  gets(s_time);
  printf("请输入结束时间 ([yyyy-mm-dd hh:mm:ss]): ");
  gets(e_time);
  printf("在此区间的数据有\n");
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
	while (1)//主界面：即目录 
  {
  printf("----------------------日志分析---------------------\n");
  printf("1=输出GET请求所占比例\n");
  printf("2=分析各访问状态码的比率\n");
  printf("3=分析访问最多的客户IP\n");
  printf("4=分析常用密码以出现次数\n");
  printf("5=输入时间段并输出在区间内的日志到文件\n");
  printf("6=退出程序\n");
  printf("请输入您的选择:\n");
   int n; scanf("%d", &n);
  if (n>7 || n<1)
   {
   printf("无效指令\n");
   }
   if(n == 1)
    {
    int get_num;
   // Print_logData(your,log_num);//输出所有的数据内容 
    get_num = static_get(your,log_num);
    printf("\n[GET] number =%d  ""GET类型请求所占的比例:%.2lf%%\n",get_num,(float)get_num/log_num*100);
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
		printf("状态码为%d，访问次数为%d，所占比例为%.2lf%%\n", chder[i], a[i], (float)a[i]/log_num*100);
	}	
	 }
	 if(n == 3)
	 {
	 	//  分析访问最多的客户IP地址，并统计其访问次数
	int max = 0;	//用来存储最多次数出
	int index = 0;//用来存储现次数最多的那个字符串的索引
	int i=0;
	int j=0;
	char* fstr;//用来暂时指向下面我们要与其它数组元素进行比较的字符串
	int temp = 0;	//用来存储*fstr字符串出现的次数
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
	printf("出现次数最多的客户ip地址：%s 访问次数 %d 次\n", your[index].Client_IP,max);
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
    int m = 0;	//用来存储最多次数出
	int ind = 0;	//用来存储现次数最多的那个字符串的索引
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
	printf("出现次数最多密码：%s 访问次数 %d 次\n", mama[ind],m);
}
    
if(n==5)
  {
   time(your);
    return (0);
  }
  }
}
