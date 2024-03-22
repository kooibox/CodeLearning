#include<stdio.h>

int mult(int a); //函数声明

int mult(int a) //函数实现
{
    if(a <= 1)
    {
        return 1;
    }else{
        return mult(a-1) * a;
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",mult(n));
    return 0;
}