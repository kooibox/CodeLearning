#include<Stdio.h>
int main()
{		
	char n;
	int i;
	int sum = 0,p =1;
	
	scanf("%d",&i);
	n = getchar();
	
	if( n%2 != 0 ){
		printf("非法输入");
	}else{
		while(i)
		{
			sum+=(i%10)*p;
			p*=2;
			i/=10;
		}
		printf("%d\n",sum);
		}
	
	
		return 0;

}
