#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>

#define MAX_NAME 30 //学生人数
#define MAX_ID 8 //学号 以88xx为例

void Input();
void OUTPUT();

typedef struct student //定义一个结构体 存放学生姓名，学号，成绩，总分，平均分
{
    char name[MAX_NAME];
    char id[MAX_ID];
    float score[2];
	float total;
	float average;
}STU;

 //定义一个结构体数组
STU s[MAX_NAME];

void Input(int num) //成绩信息录入
{

	int count = 0;
    while(1)
	{
        printf("请输入学号:>");
        scanf("%s",s[MAX_NAME].id);
        getchar();//清除换行符
        printf("请输入姓名:>");
        scanf("%s",(s[MAX_NAME].name));
		getchar();
        printf("请输入数学成绩:>"); 
        scanf("%f",&(s[MAX_NAME].score[0]));
        getchar();
        printf("请输入计算机成绩:>");
        scanf("%f",&(s[MAX_NAME].score[1]));
        getchar();
        printf("--------------------------------\n");

        s[MAX_NAME].total = s[MAX_NAME].score[0] + s[MAX_NAME].score[1];
        s[MAX_NAME].average = s[MAX_NAME].total / 2;
		count++;
        if(count == num)break;
    }
    printf("录入成功！\n");
}

void OUTPUT(int num) //成绩信息打印
{
    printf("%-15s\t%-4s\t%-8s\t%-8s\n", "名字", "学号", "数学", "计算机");
    for(int i=0;i<num;i++)
        printf("%-15s\t%-4s\t%-.1f\t%-.1f\n",s[i].name, s[i].id,
                                             s[i].score[0] , s[i].score[1]);
}
