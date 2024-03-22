#include<stdio.h>
#define MAX_NAME 10
typedef struct pay
{
	char name[MAX_NAME];
	int baseMoney;
	int floatMoney;
	int Payy;
	double ShouldPay;
}Pay;

void Shoulepay(int N,Pay PAY[])
{
	for(int i=0;i<N;i++)
	{
		scanf("%s %d %d %d",PAY[i].name,&PAY[i].baseMoney,&PAY[i].floatMoney,&PAY[i].Payy);
		PAY[i].ShouldPay = PAY[i].baseMoney + PAY[i].floatMoney - PAY[i].Payy;
	}
}

void Output(int N,Pay PAY[])
{
	for(int i=0;i<N;i++)
	{
		printf("%s %.2lf\n",PAY[i].name, PAY[i].ShouldPay);
	}
}

int main()
{
	int N;
	Pay PAY[10];
	scanf("%d",&N);
	
	Shoulepay(N,&PAY[0]);
	Output(N,&PAY[0]);
}
