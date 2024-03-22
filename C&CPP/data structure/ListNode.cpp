#include<bits/stdc++.h>
using namespace std;

typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode,*LinkList;

void InitList(LinkList &L)//初始化链表
{
	L = (LNode *)malloc(sizeof(LinkList));
	L ->next = NULL;
}

void PrintList(LinkList L)//遍历操作
{
	LNode *p = L ->next;
	while(p){
		cout <<p->data<<" ";
		p = p->next;
	}
	cout<<endl;
}

int Length(LinkList L)//求链表长度
{
	LNode *p = L ->next;
	int len = 0;
	while(p){
		len++;
		p = p-> next;
	}
	return len;
}

LinkList HeadInsert(LinkList &L)//头插法建立链表
{
	InitList(L);//初始化
	int x;
	cin >> x;
	while(x!=9999){
		LNode *s = (LNode *)malloc(sizeof(LNode));
		s ->data = x;
		s ->next = L->next;
		L->next = s;
		cin >> x;
	}
	return L;
}

LinkList TailInsert(LinkList &L)//尾插法建立单链表
{
	InitList(L);
	LNode *s,*r=L;
	int x;
	cin>>x;
	while(x!=9999){
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		cin >> x;
	}
	r->next = NULL;
	return L;
}

LNode *LocateElem(LinkList L,int x)//按值查找，查找x在链表中的位置
{
	LNode *p = L -> next;
	while(p&&p->data != x){
		p = p ->next;
	}
	return p;
}

LNode *GetElem(LinkList L,int i)//按位查找，查找在单链表中第L个位置的结点
{
	int j = 1;
	LNode *p = L->next;
	if(i==0)return L;
	if(i<1)return NULL;
	while(p&&j<i){
		p = p ->next;
		j++;
	}
	return p;//大于表长直接返回p
}

void Insert(LinkList &L,int i,int x)//将x插入第i个位置
{
	LNode *p = GetElem(L,i-1);
	LNode *s = (LNode *)malloc(sizeof(LNode));
	s ->data = x;
	s ->next = p->next;
	p ->next = s;
}

void Delete(LinkList &L,int i)//删除操作，删除链表中的第i个结点
{
	if(i<1||i>Length(L))
	{
		cout<<"delete failed:index is wrong."<<endl;
		return;
	}
	LNode *p = GetElem(L,i-1);
	LNode *q = p ->next;
	p ->next = q ->next;
	free(q);
}

int main(){
	//初始化，尾插法建立单链表
	LinkList L = TailInsert(L);
	//插入：在第二个位置插入结点，数据域为888，并遍历单链表
	Insert(L,2,888);
	cout<<"在第二个位置插入888： ";
	PrintList(L);
	//删除：删除第四个结点
	Delete(L,4);
	cout<<"删除第四个结点后：";
	PrintList(L);
	//按位查找：查找第三个结点，并输出其数据域的值
	LNode *p = GetElem(L,3);
	cout<<"第三个结点的值为："<<p->data<<endl;
	//按值查找：查找数据域为2的结点的指针
	LNode *q = LocateElem(L,2);
	cout<<"数据为2的结点的下一个结点的值为："<<q->next->data<<endl;
	//输出单链表的长度
	cout<<"单链表的长度："<<Length(L)<<endl;
	return 0;
}
