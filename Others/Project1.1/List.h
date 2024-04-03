#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define MAX_ID 5
#define MAX_NAME 50
#define InitSize 30

void InitList(SeqList* L); // 初始化顺序表 创建学生信息顺序表
void InputList(SeqList* L,STU student); // 输入学生信息
void GetElem(); // 查找学生信息(按值查找、按位查找)
void DeleteElem(SeqList* L,int id); // 删除学生信息
void ModifyList(); // 修改学生信息
bool PrintList(SeqList* L); // 输出学生信息


typedef struct {
    int* data;      // 数组指针
    int length;     // 顺序表长度
    int Maxsize;   // 最大长度
}SeqList;

typedef struct List
{
    char ID[MAX_ID]; //学号数组
    char name[MAX_NAME]; //姓名数组
    float score[3]; //成绩数组 0:英语 1:数学 2:数据结构
    char str[100]; //简介数组
    char xingbie[4];//性别数组
}STU;

STU L;

void InitList(SeqList &L) //初始化顺序表
{
    L.data = (int*)malloc(InitSize*sizeof(int)); //动态申请空间
    L.length = 0; //当前的长度为0
    L.Maxsize = InitSize; //最大长度 30
}
void InputList(SeqList* L,STU student)
{

}
bool PrintList(SeqList &L)
{
    if(!L.data)return false;//判断是否表空
    printf("学号\t姓名\t性别\t英语\t数学\t数据结构\t简介\n");
    for(int i=0;i<L.legth;i++)printf("%s %s %s %.1f %.1f %.1f %s",L.ID,
                                                                  L.name,
                                                                  L.xingbie[i],
                                                                  L.score[i].score[0],
                                                                  L.score[i].score[1],
                                                                  L.score[i].score[2],
                                                                  L.str[i]);
    return true;
}

