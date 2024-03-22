#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define InitSize 10

typedef struct//定义顺序表
{
	int length;//
	int Maxsize;
	int* data;
}SqList;

void InitList(SqList &L)//初始化顺序表
{
	L.data = (int *)malloc(InitSize*sizeof(int));
	L.length = 0;
	L.Maxsize = InitSize;
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
	int *p = L.data;
	printf("请输入你要增加的顺序表的长度:");
	scanf("%d", &len);
	L.data = (int *)malloc((L.Maxsize + len)*sizeof(int));
	for (int i = 0; i < L.length; i++)
		L.data[i] = p[i];
	L.Maxsize = L.Maxsize + len;
	free(p);
}

bool ListInsret(SqList &L)//插入元素
{
	int i, e;
	printf("请输入要插入顺序表的元素和元素位置：");
	scanf("%d %d", &e, &i);
	if (i<1 || i>L.length + 1)
		return false;
	if (L.length > L.Maxsize)
		return false;
	for (int j = L.length; j >= i; j--)
	{
		L.data[j] = L.data[j-1];
	}
	L.data[i-1] = e;
	L.length++;
	printf("插入的元素是%d，插入的位置是%d\n", e, i);
	return true;
}

bool ListDelete(SqList &L)//删除操作
{
	int i, e;
	printf("请输入要删除的元素位置：");
	scanf("%d",&i);
	if (i<1 || i>L.length + 1)
		return false;
	if (!L.data)
		return false;
	e = L.data[i - 1];
	for (int j = i; j <= L.length; j++)
	{
		L.data[j-1] = L.data[j];
	}
	L.length--;
	printf("删除的元素是%d，这个元素的位置是%d\n", e, i);
	return true;
}

bool GetElem(SqList &L)//按位查找
{
	int i;
		printf("你要找第几个元素：");
		scanf("%d", &i);
		if (i<1 || i>L.length + 1)
		{
			printf("查找失败\n");
			return false;
		}
	printf("第%d个元素是%d\n", i, L.data[i - 1]);
	return true;
}

void LocateElem(SqList &L)//按值查找
{
	int e;
	int k = 1;
	printf("输入你要查找的元素值：");
	scanf("%d", &e);
	for (int i = 0; i < L.length; i++)
	if (L.data[i] == e)
	{
		printf("找到了，是第%d个元素\n", i + 1);
		k = 0;
		break;
	}
	if (k)
		printf("找不到元素%d\n", e);
}

bool PrintList(SqList &L)//打印顺序表
{
	if (!L.data)
		return false;
	printf("顺序表里的元素有：");
	for (int i = 0; i < L.length; i++)
		printf("%d ", L.data[i]);
	printf("\n");
	return true;
}

void DestroyList(SqList &L)//销毁顺序表
{
	char a;
	getchar();
	printf("是否销毁顺序表(Y/N):");
	scanf("%c", &a);
	if (a == 'Y')
	{
		L.length = 0;
		L.Maxsize = 0;
		free(L.data);
		printf("顺序表已销毁\n");
	}
}

int Length(SqList &L)//求表长
{
	if (L.length == 0)
		return 0;
	return L.length;
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
	GetElem(L);
	LocateElem(L);
	int len = Length(L);
	printf("顺序表的表长:%d\n", len);
	DestroyList(L);
	return 0;
}

