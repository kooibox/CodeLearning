#include<Stdio.h>

void printElement(int e)
{
	e *= 10;
	printf("%d ",e);
}

int main()
{
	int a[1000];
	int i;
	char n;
	
	for(int i = 0;i < 1000;i++){
		scanf("%d",&a[i]);
		n = getchar();
	if(n == 'e')break;
		printElement(a[i]);}
	printf("\n");
	for(int i = 0;i <= i;++i)
		printf(" %d ",a[i]);
}
