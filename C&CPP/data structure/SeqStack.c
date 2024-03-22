#include<stdio.h>
#include<stdlib.h>

void StackInit(ST* ps);//初始化
void Stackpush(ST* ps,STtype x);//入栈
void STackPop(ST* ps);//出栈
int StackTOP(ST* ps);//获取栈顶元素
void STDestory(ST* ps);//销毁栈
bool STEmpty(ST* ps);//判断栈是否为空
int STsize(ST* ps);//获取栈的总元素

typedef int STtype;
typedef struct stack
{
    STtype *data;
    int top;
    int capacity;
}ST;

void StackInit(ST* ps)
{
    ps->data = (STtype*)malloc(sizeof(STtype) * 4);
    if(!ps->data)
    {
    printf("malloc fail");
    exit(-1);
    }
    ps->capacity = 4;
    ps->top = 0;
}//初始化，top表示栈的元素个数

void Stackpush(ST* ps,STtype x)
{
    assert(ps);
    if(ps->top == ps ->capacity)
    {
        STtype* temp = (STtype*)realloc(ps->data,sizeof(STtype)* ps->capacity *2);
        if(temp == NULL)
        {
       printf("realloc fail");
            exit(-1);
        }
        ps->data = temp;
        ps->capacity *= 2;
    }
    ps->data[ps->top++] = x;
}//入栈

bool STEmpty(ST* ps)
{
    assert(ps);
    return ps->top == 0;
}

void StackPop(ST* ps)
{
    assert(ps);
    assert(!STEmpty(ps));
    ps->top--;
}


