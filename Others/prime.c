#include<stdio.h>
#include<stdlib.h>

int main()
{
	int N;
	int a[N+1],i,x;
	for (i = 0; i < N; i++)
		scanf("%d", &a[i]);//输入有序数组
	printf("要插入的数是:");
	scanf("%d", &x);//输入插入的数
	for (i = N - 1; i >= 0; i--);//倒序比较
	if (a[i] > x){
		a[i + 1] = a[i];
	}else{
		goto FLAG;
	}
	FLAG:
	a[i + 1] = x;
	for (i = 0; i < N+1; i++)
		printf("%d", a[i]);//输出数据
	return 0;
}
