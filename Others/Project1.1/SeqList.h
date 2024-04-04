#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct student
{
    char name[20];
    char gender[5];
    char id[5];
    float score[3];
}STU;

typedef struct SeqList
{
    STU* L;
    int size;
    int capacity;
}SL;

//打印
void SLPrint(SL* ps);

//初始化与销毁
void SLInit(SL* ps);
void SLDestroy(SL* ps);

//尾插尾删
void SLPushBack(SL* ps,STU* x);
void SLPopBack(SL* ps);

// 头插头删
void SLPushFront(SL* ps, SLDataType* x);
void SLPopFront(SL* ps);

// 顺序表查找
int SLFind(SL* ps, int x); 
int Find(SL* ps, int sno);

// 顺序表在pos位置插入x
void SLInsert(SL* ps, int pos, SLDataType* x);
// 顺序表删除pos位置的值
void SLErase(SL* ps, int pos);

// 扩容函数
void SLCheckCapacity(SL* ps);


