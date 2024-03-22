#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NAME 30
#define MAX_ID 15

typedef struct Student //定义结构体
{
    char name[MAX_NAME];
    char id[MAX_ID];
    float score[3];
	float total;
	float average;
}Student;

typedef Student SLTDataType;

typedef struct SListNode //定义单链表
{
    SLTDataType data;//数据域
    struct SListNode* next;//next指向当前节点的下一个节点
}SListNode;

SListNode* createHead()
{
    SListNode*plist = (SListNode *)malloc(sizeof(SListNode));
    if(plist == NULL)
    {
        printf("创建表头失败！\n");
        exit(-1);
    }
    plist -> next = NULL;
    return plist;
}

//动态申请一个节点，返回新申请结点的地址
SListNode* BuyListNode(const SLTDataType x)
{
	SListNode* plist = (SListNode *)malloc(sizeof(SListNode));
	//判断申请是否成功
	if (plist == NULL)
	{
		printf("申请新节点失败!\n");
		exit(-1);
	}
	plist->data = x;
	plist->next = NULL;
	return plist;
}

//尾插法添加数据
void INPUT(SListNode** pplist)
{
    Student s;

    printf("请输入姓名:>");
    scanf("%s",s.name);
    getchar();
    printf("请输入学号:>");
    scanf("%s",s.id);
    getchar();
    printf("请输入数学成绩:>");
    scanf("%f",&(s.score[0]));
    getchar();
    printf("请输入计算机成绩:>");
    scanf("%f",&(s.score[1]));
    getchar();

	s.total = s.score[0] + s.score[1];
	s.average = s.total / 2;

    printf("录入成功\n");

    //申请一个新节点
	SListNode* NewNode = BuyListNode(s);

	//定义一个当前节点tail去找链表的尾节点
	SListNode* tail = *pplist;
	
	//遍历节点找尾节点
	while (tail->next != NULL)
	{
		tail = tail->next;
	}
	//尾节点的next指向新节点
	tail->next = NewNode;
}

//成绩信息打印
void OUTPUT(const SListNode* plist)
{
	SListNode* cur = plist->next;
	
	printf("%-15s\t%-15s\t%-8s\t%-8s\n", "名字", "学号", "数学", "计算机");
	//打印链表
	while (cur)
	{
		//printf("%d->", cur->data);
		printf("%-15s\t%-15s\t%-8.2lf\t%-8.2lf\n", cur->data.name,
			cur->data.id,
			cur->data.score[0],
			cur->data.score[1]
);
		cur = cur->next;	//节点指向下一个
	}
}
static void MAX(SListNode** pplist)
{
	printf("%-15s\t%-15s\t%-8s\n","名字","学号","计算机");
	SListNode* p = (*pplist)->next;
	SListNode* q = p->next;
	for (; p != NULL; p = p->next)
	{
		for (; q != NULL; q = q->next)
		{
			if (p->data.score[1] < q->data.score[1])
			{
				SListNode tmp;
				tmp.data = p->data;
				p->data = q->data;
				q->data = tmp.data;
			}
		}
		printf("%-8s\t%-15s\t%.1f\n",p->data.name,p->data.id,p->data.score[1]);
		break;
	}
}
void AVG(const SListNode* plist)
{
	SListNode* cur = plist->next;

	cur->data.total = cur->data.score[0] + cur->data.score[1];
	cur->data.average = cur->data.total / 2;

	printf("%-15s\t%-15s\t%-8s\t\n", "名字", "学号", "平均分");
	while(cur)
	{
		printf("%-15s\t%-15s\t%-8.2lf\n",cur->data.name,cur->data.id,cur->data.average);
		cur = cur->next;
	}
}
void PASS(const SListNode* plist)
{
	int PassScore = 60;
	int temp = 0;
	SListNode* cur = plist->next;

	while(cur)
	{
		if(cur->data.score[0] >= PassScore && cur->data.score[1] >=PassScore)temp++;
		cur = cur ->next;
	}
	printf("           --------------------两门科目均及格的共有学生%d人--------------------          \n",temp);
}
