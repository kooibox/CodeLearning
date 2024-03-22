#include<bits/stdc++.h>
using namespace std;

typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*LinkList;

void InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LinkList));
    L -> next = NULL;
}

void PrintList(LinkList L)
{
    LNode *p = L ->next;
    while(p){
        cout << p->data<<" ";
        p = p ->next;
    }
    cout << endl;
}

int Length(LinkList L)
{
    LNode *p = L ->next;
    int len = 0;
    while(p)
    {
        len++;
        p = p->next;
    }
    return len;
}

LNode *LocateElem(LinkList L,int x)
{
    LNode *p = L ->next;
    while(p&&p->data != x)
    {
        p = p ->next;
    }
    return p;
}

LNode *GetElem(LinkList L,int i)
{
    int j = 1;
    LNode *p = L ->next;
    if(i==0)return L;
    if(i<1)return NULL;
    while(p&&j<i)
    {
        p = p ->next;
        j++;
    }
    return p;
}

