#include <stdio.h> //包含标准输入输出流的头文件
#include <assert.h> //包含断言的头文件
#include <stdlib.h> //包含增容等的头文件

typedef int SLDataType; //类型重命名

typedef struct SeqList
{
	SLDataType* a; //定义一个指针变量为了接下来动态内存的开辟
	int size; //记录顺序表存储元素的个数
	int capacity; //记录顺序表当前的容量大小(最多能存储多少个数据)
}SL; //结构体重命名

void SeqListInit(SL* ps); //顺序表的初始化

void SeqListPrint(SL* ps); //顺序表的打印

void SeqListDestroy(SL* ps); //顺序表的销毁

void SeqListCheckCapacity(SL* ps); //顺序表检查是否增容

void SeqListBackPush(SL* ps, SLDataType x); //顺序表的尾插

void SeqListBackPop(SL* ps); //顺序表的尾删

void SeqListFrontPush(SL* ps, SLDataType x); //顺序表的头插

void SeqListFrontPop(SL* ps); //顺序表的头删

int SeqListFind(SL* ps, SLDataType x); //顺序表的查找

void SeqListInsert(SL* ps, int pos, SLDataType x); //顺序表的任意插入

void SeqListErase(SL* ps, int pos); //顺序表的任意位置删除
