#define _CRT_SECURE_NO_WARNINGS
#define MAXSIZE 1000
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>


//定义学生信息
typedef struct {
	char name[10];//姓名
	char number[10];//学号
	double price;
}student;
typedef student ElemType;


//顺序表动态定义
typedef struct {
	ElemType* elem;
	int length;
}Sqlist;

//初始化顺序表
int InitList(Sqlist&L) {
	L.elem = new ElemType[MAXSIZE];
	if (!L.elem) exit(0);
	L.length = 0;
	return 1;
}
void Input(ElemType* e)
{
	printf("姓名:");	scanf("%s", e->name);
	printf("学号:");	scanf("%s", e->number);
	printf("成绩:");	scanf("%lf", &e->price);
	printf("输入完成\n\n");
}

//返回学生信息
ElemType getelem(Sqlist L, int i)
{
	return L.elem[i];
}
void Output(ElemType*e)
{
	printf("姓名:%-20s\n学号:%-10s\n成绩:%-10.2lf\n\n", e->name, e->number, e->price);
}
int search(Sqlist L, char str[])
{
	for (int i = 1; i <= L.length; i++)
	{
		if (strcmp(L.elem[i].name, str) == 0)
			return i;
		return 0;
	}
}
int insert(Sqlist L, int i, ElemType c)
{
	if ((i<1 || i>L.length + 1))
		return 0;
	if (L.length == MAXSIZE)	return 0;
	for (int j = L.length; j >= i; j--)
	{
		L.elem[j + 1] = L.elem[j];
	}
	L.elem[i] = c;
	++L.length;
	return 1;
}

int ListDelete(Sqlist L,int i)
{
	if ((i < 1) || (i > L.length))	return 0;
	for (int j = i; j <= L.length; j++)
	{
		L.elem[j] = L.elem[j + 1];
	}
	--L.length;
	return 1;
}
int main()
{
	int choice, n, i;
	ElemType a, b, c;
	Sqlist L;
	printf("*******************学生管理系统***********\n");
	printf("1.输入学生信息\n");
	printf("2.显示学生表信息\n");
	printf("3.根据姓名进行查找\n");
	printf("4.显示指定的位置学生信息\n");
	printf("5.在指定位置插入学生信息\n");
	printf("6.删除指定位置的学生记录\n");
	printf("7.统计学生人数\n");
	printf("8.退出\n\n");
	while (1)
	{
		printf("请您选择 ：");
		scanf("%d", &choice);
		switch (choice)
		{
			case 1:printf("正在为您自动创建顺序表，请您等待~~\n");
			InitList(L);
			if (InitList(L))
			{
				printf("已创建成功.\n");
			}
			else
			{
				printf("创建失败\n");
				break;
			}
			printf("请您输入你要输入的学生人数：");
			scanf("%d", &n);
			for (i = 1; i <= n; i++)
			{
				printf("第%d个学生:\n", i);
				Input(&L.elem[i]);
			}
			L.length = n;
			break;
		case 2:
			for (i = 1; i <= n; i++)
			{
				a = getelem(L, i);
				Output(&a);
			}
			break;
		case 3:
			char str[15];
			printf("请输入要查找的学生姓名:");
			scanf("%s", str);
			if (search(L, str))
			{
				Output(&L.elem[search(L, str)]);
			}
			else {
				printf("没有此学生信息！\n"); break;
			}
		case 4:
			printf("请输入要查询的位置:");
			int id1;
			scanf("%d", &id1);
			b = getelem(L, id1);
			Output(&b);
			break;
		case 5:
			printf("请输入要插入的位置:");
			int id2;
			scanf("%d", &id2);
			printf("请输入学生信息:\n");
			Input(&c);
			if (insert(L,id2,c))
			{
				n++;
				puts("插入成功");
			}
			else
			{
				puts("插入失败");
			}
			break;
		case 6:
			printf("请输入要删除的位置:");
			int id3;
			scanf("%d", &id3);
			if (ListDelete(L, id3))
			{
				n--;
				puts("删除成功");
			}
			else
			{
				puts("删除失败");
			}
			break;
			case 7:printf("已录入的学生个数为:%d\n\n", L.length);
			break;
			case 8:break;
		}
	}
	return 0;
}
