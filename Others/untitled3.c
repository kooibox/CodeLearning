#include<stdio.h>
void main()
{   int n,sum=0,p=1;          //n为二进制数，sum为每一位计算所加的和，p为位权
	scanf("%d",&n);          //输入该二进制数
	while(n)               //循环条件为n，即二进制数n在不为0的时候程序一直成立
	{ sum+=(n%10)*p;       //数字中所有位乘以本位的位权再加和
		p*=2;                //位权随着位的变化依次增加
		n/=10; }             //进行下一位的输出
	
	printf("%d\n",sum);
	
}
