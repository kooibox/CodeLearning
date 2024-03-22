#include<stdio.h>
#include<stdlib.h>

typedef struct student //定义一个结构体 存放学生姓名，学号，成绩，总分，平均分
{
    char name[30];
    int id;
    float score[2];
	float total;
	float average;
}STU;

enum Optinon
{
    Exit,//0
    Add,//1
    Show,//2
    Max,//3
    Avg,//4
    Pass,//5
};

void menu()//菜单函数
{
	printf("*************  成绩管理系统  ****************\n");
	printf("*****  1. Add          2. Show        *******\n");
	printf("*****  3. Max          4. Avg         *******\n");
	printf("*****  5. Pass         0. Exit        *******\n");
	printf("*********************************************\n");
}

void Input(int *num_,STU Stu[])
{
	printf("请按顺序输入%d个学生的信息:(学号_姓名_数学成绩_计算机成绩)\n",*num_);
	for(int i=0;i<*num_;i++)
	{
		scanf("%d",&Stu[i].id);
		scanf("%s",&Stu[i].name);
		scanf("%f",&Stu[i].score[0]);
		scanf("%f",&Stu[i].score[1]);

		Stu[i].total = Stu[i].score[0] + Stu[i].score[1];
		Stu[i].average = Stu[i].total / 2;
	}
	printf("录入成功！\n");
}

void OUTPUT(int *num_,STU Stu[])
{
	printf("学号\t姓名\t数学成绩\t计算机成绩\n");
	for(int i = 0;i<*num_;i++)
	{
		printf("%d\t%s\t%.1f\t        %.1f\n",Stu[i].id,Stu[i].name,Stu[i].score[0],Stu[i].score[1]);
	}
}

void MAX(int *num_,STU Stu[])
{
	STU temp; //创建临时变量存储信息
	printf("学号\t姓名\t计算机成绩\n");
	for(int i = 0;i<*num_-1;i++)//冒泡排序法筛选出计算机成绩最高者
	{
		for(int j = i+1;j<*num_;j++)
		{
			if(Stu[i].score[1]>Stu[j].score[1])
			{
				temp=Stu[j];
				Stu[j]=Stu[i];
				Stu[i]=temp;
			}
			printf("%d\t%s\t%.1f\t\n",Stu[j].id,Stu[j].name,Stu[j].score[1]);
			break;
		}
	}

}

void AVG(int *num_,STU Stu[])
{
	printf("学号\t姓名\t数学成绩\t计算机成绩\t平均分\n");
	for(int i = 0;i<*num_;i++)
	{
		printf("%d\t%s\t%.1f\t        %.1f\t        %.1f\n",Stu[i].id,Stu[i].name,Stu[i].score[0],Stu[i].score[1],Stu[i].average);
	}
}

void PASS(int *num_,STU Stu[])
{
	int PassScore = 60;
	int count = 0;

	for(int i=0;i<*num_;i++)
	{
		if(Stu[i].score[0] >= PassScore && Stu[i].score[1] >= PassScore)count++;
	}
	printf("           --------------------两门科目均及格的共有学生%d人--------------------          \n",count);
}

int main()
{
    int input = 0;
	int num;
	int *num_ = &num;
	STU Stu[30];

    do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case Add:
			printf("请输入本次录入数据的大小:>");
			scanf("%d",&num);
			Input(num_,&Stu[0]);
			break;
		case Show:
			OUTPUT(num_,&Stu[0]);
			break;
		case Max:
			MAX(num_,&Stu[0]);
			break;
		case Avg:
			AVG(num_,&Stu[0]);
			break;
		case Pass:
			PASS(num_,&Stu[0]);
			break;
		case Exit:
			printf("退出该系统\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
}
