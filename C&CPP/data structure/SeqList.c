#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

void SeqListInit(SL* ps)
{
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}  //顺序表的初始化

void SeqListPrint(SL* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; ++i)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
} //顺序表的打印

void SeqListDestroy(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
} //顺序表的销毁

void SeqListCheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
        int newcapacity;
		newcapacity = (ps->capacity == 0 ? ps->capacity = 4 : ps->capacity * 2);
		SLDataType* tmp = (SLDataType*)realloc(ps->a, newcapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			printf("realloc invalid!\n");
			exit(-1); //退出程序
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
} //顺序表检查是否增容

void SeqListBackPush(SL* ps, SLDataType x)
{
	//SeqListCheckCapacity(ps); //检查是否需要增容

	//int end = ps->size;
	//ps->a[end] = x;
	//ps->size++;

	SeqListInsert(ps, ps->size, x);
} //顺序表的尾插

void SeqListBackPop(SL* ps)
{
	//粗暴的方式
	//assert(ps->size > 0);

	//温柔的方式
	///*if (ps->size <= 0)
	//{
	//	printf("SeqListBackPop invalid!\n");
	//	return;
	//}*/

	//ps->size--;

	SeqListErase(ps, ps->size - 1);

}//顺序表的尾删

void SeqListFrontPush(SL* ps, SLDataType x)
{
	//SeqListCheckCapacity(ps); //检查是否需要增容

	//int end = ps->size;
	//while (end >= 0)
	//{
	//	ps->a[end] = ps->a[end - 1];
	//	end--;
	//}
	//ps->a[0] = x;
	//ps->size++;

	SeqListInsert(ps, 0, x);
} //顺序表的头插

void SeqListFrontPop(SL* ps)
{
	//粗暴的方式
	//assert(ps->size > 0);

	//温柔的方式
	///*if (ps->size <= 0)
	//{
	//	printf("SeqListFrontPop invalid!\n");
	//	return;
	//}*/

	//int begin = 0;
	//while (begin < ps->size)
	//{
	//	ps->a[begin] = ps->a[begin+1];
	//	begin++;
	//}
	//ps->size--;

	SeqListErase(ps, 0);
} //顺序表的头删

int SeqListFind(SL* ps, SLDataType x)
{
	int i = 0;
	for (i = 0; i < ps->size; ++i)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;
} //顺序表的查找

void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	SeqListCheckCapacity(ps);

	//粗暴的方式
	assert(pos >= 0 && pos <= ps->size);

	//温柔的方式
	/*if (pos<0 || pos>ps->size)
	{
		printf("SeqListInsert invalid!\n");
		return;
	}*/

	int end = ps->size;
	while (end >= pos)
	{
		ps->a[end] = ps->a[end - 1];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;
} //顺序表的任意插入

void SeqListErase(SL* ps, int pos)
{
	//粗暴的方式
	assert(pos >= 0 && pos < ps->size);

	//温柔的方式
	/*if (pos < 0 || pos >= ps->size)
	{
		printf("SeqListErase invalid!\n");
		return;
	}*/

	int begin = pos;
	while (begin < ps->size)
	{
		ps->a[begin] = ps->a[begin + 1];
		begin++;
	}
	ps->size--;
} //顺序表的任意位置删除

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

