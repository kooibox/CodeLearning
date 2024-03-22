#include<stdio.h>

int test(int n1){
	int sum = n1 + 1;
	printf("sum = %d",sum);
	return 0;
}

void main(){
	int n2=6;
	test(n2);
}

