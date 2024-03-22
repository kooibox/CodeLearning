//变量交换的方法：1.加减法 2.异或法 3.乘除法 4.第三变量法

#include<stdio.h>

int main()
{   //1.加减法
    int a = 5;
    int b = 10;

    a = a + b;
    b = a - b;
    a = a - b;
    printf("加减法交换：");
    printf("a=%d,b=%d\n",a,b);

    //2.异或法
    a = a^b;
    b = a^b;
    a = a^b;
    printf("异或法交换：");
    printf("a=%d,b=%d\n",a,b);
}