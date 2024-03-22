#define _CRT_SECURE_NO_WARNINGS 1


#include "SeqList.h"

void TestSeqList1()
{
	SL s1;
	SeqListInit(&s1);
	SeqListBackPush(&s1, 0);
	SeqListBackPush(&s1, 1);
	SeqListBackPush(&s1, 2);
	SeqListBackPush(&s1, 3);
	SeqListBackPush(&s1, 4);

	SeqListBackPop(&s1);
	SeqListBackPop(&s1);
	SeqListBackPop(&s1);

	SeqListFrontPush(&s1, 2);
	SeqListFrontPush(&s1, 3);
	SeqListFrontPush(&s1, 4);
	SeqListFrontPush(&s1, 5);
	SeqListFrontPush(&s1, 6);

	SeqListFrontPop(&s1);
	SeqListFrontPop(&s1);
	SeqListFrontPop(&s1);
	SeqListFrontPop(&s1);



	SeqListPrint(&s1);
}

void TestSeqList2()
{
	SL s1;
	SeqListInit(&s1);

	SeqListInsert(&s1, 0, 0);
	SeqListInsert(&s1, 1, 1);
	SeqListInsert(&s1, 2, 2);
	SeqListInsert(&s1, 3, 3);
	SeqListInsert(&s1, 4, 4);
	SeqListErase(&s1, 1);
	SeqListErase(&s1, 2);


	SeqListPrint(&s1);
	SeqListDestroy(&s1);
}

int main()
{
	TestSeqList1();
	//TestSeqList2();
	return 0;
}
