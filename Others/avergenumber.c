#include<stdio.h>

int main(){
	int sum = 0;
	int number;
	int count = 0;
	
	scanf("%d",&number);

	while(number != -1){
		sum += number;
		count ++;
		scanf("%d",&number);
	}
	printf("The averagernumber is %d\n",sum/count);
}
