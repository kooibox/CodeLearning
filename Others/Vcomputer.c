#include<stdio.h>

int main()
{
    int i = 15;
    int a = 1;
    int b = 1;
    int count = 0;
    while (a < i )
    {
        a++;
        b += a;
        count++;
    }
    printf("结果为：%d\n",b);
    printf("运行了%d次",count);

    return 0;
}