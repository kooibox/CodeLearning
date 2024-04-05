#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct  Log
{
    char Clientip[20];//客户端ip
    char Method[10];//请求方式
    char Status[10];//状态
    char Size[10];//返回域大小
};
