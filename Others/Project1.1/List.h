#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ID 5
#define MAX_NAME 50
#define MAX_SIZE 30

void InitList(SeqList* L); // 初始化顺序表 创建学生信息顺序表
void InputList(SeqList* L,STU student); // 输入学生信息
void GetElem(); // 查找学生信息(按值查找、按位查找)
void DeleteElem(SeqList* L,int id); // 删除学生信息
void ModifyList(); // 修改学生信息
void PrintList(SeqList* L); // 输出学生信息


typedef struct {
    STU data[Max_SIZE];      // 数组指针
    int length;     // 顺序表长度
}SeqList;

typedef struct List
{
    char ID[MAX_ID]; //学号数组
    char name[MAX_NAME]; //姓名数组
    float score[3]; //成绩数组 0:英语 1:数学 2:数据结构
    char str[100]; //简介数组
    char gender[10];//性别数组
}STU;

STU L;

void InitList(SeqList &L) //初始化顺序表
{
    L.data = (int*)malloc(InitSize*sizeof(int)); //动态申请空间
    L.length = 0; //当前的长度为0
    L.Maxsize = MAX_SIZE; //最大长度 30
}
void InputList(SeqList* L,STU* student)
{
    printf("请以此输入%d个学生的学号-姓名-性别-英语成绩-数学成绩-数据结构成绩-简介\n",L->length);
    for(int i=0;i<L->length;i++)
    scanf("%s %s %s %.1f %.1f %.1f %s",student->ID,student->name,
                                       student->gender,&student->score[0],
                                       &student->score[1],&student->score[2],
                                       &student->str[i]);
}
// void AddStudent(SeqList* list, STU student) {
//     if (list->length >= MAX_SIZE) {
//         printf("顺序表已满，无法添加更多的学生。\n");
//         return;
//     }
//     list->data[list->length] = student;
//     list->length++;
// }

void PrintList(SeqList* L)
{
    if(!L.data)return false;//判断是否表空
    printf("学号\t姓名\t性别\t英语\t数学\t数据结构\t简介\n");
    for(int i=0;i<L.length;i++)
    printf("%s %s %s %.1f %.1f %.1f %s",L.ID,
                                        L.name,
                                        [i],
                                        L.score[i].score[0],
                                        L.score[i].score[1],
                                        L.score[i].score[2],
                                        L.str[i]);
    return true;
}

void DeleteElem(SeqList* L,char* id) //通过学号寻找要删除的学生
{
    int i;
    for(i=0;i<L->length;i++){
        if(strcmp(L->data[i].ID,id) == 0)break;
    }

    //如果找不到，则返回错误信息
    if(i==L->length){
        printf("找不到学号为%s的学生。\n",id);
        return;
    }

    //删除操作
    for(int j = i;j<L->length - 1;j++){
        L->data[j] = L->data[j+1];
    }
}

void ModifyList(SeqList* L,char* id){ //通过学号查找要修改的学生
    int i;
    for(i=0;i<L->length;i++){
        if(strcmp(L->data[i].ID,id) == 0)break;
    }

    //如果找不到，则返回错误信息
    if(i==L->length){
        printf("找不到学号为%s的学生。\n",id);
        return;
    }
}
// 修改学生信息
void ModifyList(SeqList* L,char* id){
    for(int i=0;i<L->length;i++){
            if(strcmp(L->data[i].ID,id) == 0)break;
        }
    if(i==L->length){
            printf("找不到学号为%s的学生。\n",id);
            return;
        }
} // 修改学生信息