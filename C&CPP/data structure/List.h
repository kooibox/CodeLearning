#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ID 4
#define MAX_NAME 30
#define Introduction 50
#define InitSize 30

typedef struct //针对学生的信息
{
    char id[MAX_ID]; //学号
    char name[MAX_NAME]; //姓名
    char Gender; //性别
    float Score[3];//英语[0],数学[1],数据结构[2]
    char Str[Introduction]; //简介
    
}STU;

typedef struct 
{
    STU* elem;
    int length;
}Slist;


int InitList(Slist& L)//初始化顺序表
{
    L.elem = new STU[InitSize];
    if(!L.elem)exit(0);
    L.length = 0;
    return 1;
}

void Input(STU* e,int num)
{
    printf("请按顺序输入%d个学生的信息:(学号_姓名_性别_数学成绩_计算机成绩_数据结构_简介)\n",num);
    for(int i=0;i<num;i++)
	{
		scanf("%s",e->id);
		scanf("%s",e->name);
		scanf("%s",&e->Gender);
		scanf("%f",&e->Score[0]);
        scanf("%f",&e->Score[1]);
        scanf("%f",&e->Score[2]);
        scanf("%s",e->Str);
	}

}
