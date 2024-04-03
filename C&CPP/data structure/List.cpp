#include<stdio.h>
#include<stdlib.h>
#define InitSize 10


typedef struct//定义一个顺序表结构
{
	int length;//长度
	int Maxsize;//最大长度
	int *data;//数组指针
}SqList;

void InitList(SqList &L)//初始化顺序表
{
	L.data = (int*)malloc(InitSize*sizeof(int));//申请空间
	L.length = 0; //当前长度为0
	L.Maxsize = InitSize; //最大长度
}

void WriteList(SqList &L)//把元素放入顺序表
{
	printf("请输入你要创建的顺序表的长度：");
	scanf("%d", &L.length);
	printf("请输入%d个你要放入顺序表里的元素：",L.length);
	for (int i = 0; i < L.length; i++)
		scanf("%d", &L.data[i]);
}

void IncreaseSize(SqList &L)//增加顺序表的长度
{
	int len;
	int *p = L.data;//*p指向的地址和顺序表的首地址一样
	printf("请输入你要增加的顺序表的长度");
	scanf("%d",&len);
	L.data = (int *)malloc((L.Maxsize + len)*sizeof(int));//申请一个新空间
	for(int i=0;i<L.length;i++)
	{
		L.data[i] = p[i];//把值传递过新的顺序表里
	}
	L.Maxsize = L.Maxsize + len; //顺序表的最大长度加上len
	free(p);//释放空间
}

bool GetELem(SqList &L)//查找元素 按位查找，直接通过数组下标定位
{
	int i;
	printf("你要找第几个元素：");
	scanf("%d",&i);
	if(i<1||i>L.length+1)
	{
		printf("查找失败");
		return false;
	}
	printf("第%d个元素是%d\n",i,L.data[i-1]);
	return true;
}

void LocatElem(SqList &L)//查找元素 按值查找 对顺序表进行遍历
{
	int e;
	int k = 1;
	printf("请输入你要查找的元素：");
	scanf("%d",&e);
	for(int i=0;i<L.length;i++)
		if(L.data[i]==0)
		{
			printf("找到了，是第%d个元素\n",i+1);
			k = 0;
			break;
		}
		if(k)
			printf("找不到元素%d\n",e);
	
}

bool ListInsret(SqList &L)//元素插入
{
	int i,e;
	printf("请输入要插入的元素和位置：");
	scanf("%d %d",&e,&i);
	if(i<1||i>L.length+1)//判断是否越界
		return false;
	if(L.length > L.Maxsize)//判断存储空间是否已满
		return false;
	for(int j = L.length;j>=i;j--)
	{
		L.data[j] = L.data[j-1];//把元素逐个后移
	}
	L.data[i-1] = e; //新元素放入下标为i-1的位置
	L.length++;//表长+1
	printf("插入的元素是%d,插入的位置是%d\n",e,i);
	return true;
}

bool ListDelete(SqList &L)
{
	int i,e;
	printf("请输入要删除的元素位置：");
	scanf("%d",&i);
	if(i<1||i>L.length + 1)
		return false;
	if(!L.data)
	{
		printf("空表\n");
		return false;
	}
	e = L.data[i-1];
	for(int j=i;j<=L.length;j++)
	{
		L.data[j-1] = L.data[j];
	}
	L.length--;//表长减一
	printf("删除的元素是%d,这个元素的位置是%d\n",e,i);
	return true;
}

bool PrintList(SqList &L) //顺序表的打印
{
	if(!L.data)
		return false;
	printf("顺序表里的元素有：");
	for(int i=0;i<L.length;i++)
		printf("%d",L.data[i]);
	printf("\n");
	return true;
}

int Length(SqList &L)//求表长
{
	if(L.length == 0)
		return 0;
	return L.length;
}

void DestroyList(SqList &L)
{
	char a;
	getchar();
	printf("是否销毁顺序表（Y/N):");
	scanf("%c",&a);
	if(a == 'Y')
	{
		L.length = 0;
		L.Maxsize = 0;
		free(L.data);
		printf("顺序表已销毁");
	}
}

 int main()
{
	SqList L;
	InitList(L);
	WriteList(L);
	PrintList(L);
	IncreaseSize(L);
	ListInsret(L);
	PrintList(L);
	ListDelete(L);
	PrintList(L);
	GetELem(L);
	LocatElem(L);
	int len = Length(L);
	printf("顺序表的表长:%d\n", len);
	DestroyList(L);
	return 0;
}
