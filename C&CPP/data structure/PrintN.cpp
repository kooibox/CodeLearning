#include<stdio.h>
using namespace std;

void print1N(int num)
{
	if(num)
	{
		print1N(num-1);
		printf("%d ",num);
	}
	return;
}

int main()
{
	int num;
	scanf("%d",&num);
	print1N(num);
	return 0;
}
