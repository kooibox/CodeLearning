#include"SeqList.h"
#include<iostream>
#include<cstdio>

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
int main()
{
    SL sl;
    SLInit(&sl);

    int input = 0;
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case Add:
			INPUT(&Plist);
			break;
		case Show:
			OUTPUT(Plist);
			break;
		case Max:
			MAX(&Plist);
			break;
		case Avg:
			AVG(Plist);
			break;
		case Pass:
			PASS(Plist);
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


// #include "SeqList.h"

// void TestSeqList()
// {
// 	SL sl;
// 	SLInit(&sl);

// 	SLDataType stu1 = { "张三", "男", 110701, 22 };
// 	SLDataType stu2 = { "李四", "男", 110702, 21 };
// 	SLDataType stu3 = { "王五", "女", 110703, 23 };
// 	SLDataType stu4 = { "赵六", "女", 110704, 22 };
// 	SLDataType stu5 = { "周七", "男", 110705, 23 };

// 	SLPushBack(&sl, &stu1);
// 	SLPushBack(&sl, &stu2);
// 	SLPushBack(&sl, &stu3);
// 	SLPushBack(&sl, &stu4);
// 	SLPrint(&sl);

// 	SLInsert(&sl, 2, &stu5);
// 	SLPrint(&sl);
// 	// 查找可以有多种方式，按照不同的信息查找，这里只是以学号为例
// 	int n = SLFind(&sl, 110703);
// 	printf("%d\n", n);

// 	SLErase(&sl, 2);
// 	SLPrint(&sl);

// 	SLDestroy(&sl);
// }
// int main() 
// {
// 	TestSeqList();

// 	return 0;
// }
