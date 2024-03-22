#include<Stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void){
	srand(time(0));
	int r = rand()%100+1;
	int flag = 0,sum = 1;
	int n = 0;
	
	printf("我已经想好了一个1到100之间的数了。\n");
	do{
		printf("请猜猜这个数\n");
		scanf("%d",&n);	
		sum ++;
		if(n == r){
			flag = 1;
		}else{
			flag = 0;
		}
	switch(flag){
	case 1:
		printf("你猜对了，真棒！\n");
		break;
	case 0:
		if(n < r){
		printf("猜小了，继续努力\n");
		}else{
		printf("猜大了，继续加油\n");}
		if(sum > 3){
		printf("三次结束，你没有猜对，很遗憾\n");
		break;
		}
	}
	}while(n != r);
}
