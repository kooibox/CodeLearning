#include "score.h"
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
	SListNode* Plist = createHead();	//定义一个单链表
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

	return 0;
}

