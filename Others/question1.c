#include<Stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

char a[1000];

int main(){
	int len,i,num = 0,sum = 0,b,d;
	for(i=1;i<=1000;i++){
		scanf("%c",&a[i]);
		if(a[i]=='e')
		{
			d = i - 1;//字符串数据的个数
			len = (i+1)/2-1;//字符串数字的个数
			break;
		}
	}
	b = len-1;//求该二进制数的位数，len减去e
	for(i=d;i>=1;i--){//使用遍历的方法逆序输出
		if(i%2==1)
		{
			printf("%c",a[i]);
			sum +=pow(2,b)*(a[i]-48);//从右到左用二进制的每个数去乘以2的相应次方相加
			b--;
		}
	}
	printf("\n%d",sum);
	
	return 0;
}
