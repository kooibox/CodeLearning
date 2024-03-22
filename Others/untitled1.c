#include<stdio.h>
int main()
{ int a, b, i, t, sum; /*①*/
	printf("input a: ");
	scanf("%d",&a);
	printf("input b: ");
	scanf("%d",&b);
	t = a;
	for(i=a; i<=b; i++) /*②*/
		if(t%7==0) printf("%d",t);
	printf("\n");
}

