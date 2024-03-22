#include<stdio.h>
#include<string.h>
#include<assert.h>
	
int t;

int My_srtcmp(const char*a,const char*b){
	assert(a);
	assert(b);
	while(*a == *b)
	{
	if(*a == '\0')
	{
	t = 0;
	}
	a++;
	b++;
	}
	if(a>b)
	{
	t = 1;
	}
	else
	{
	t = -1;
	}
	switch (t) {
	case 0:
		printf("strcmp(a,b)的结果是0\n");
		printf("所以a = b");
		break;
	case 1:
		printf("strcmp(a,b)的结果是1\n");
		printf("所以a > b");
		break;
	case -1:
		printf("srtcmp(a,b)的结果是-1\n");
		printf("所以a < b");
		break;
	}
}//比较大小
char* lianjie(char *a,const char *b){
	char* ret = a;
	while(*a)
	{
		a++;
	}
	while(*a++ - *b++){
		;
	}
	return ret;
	printf("%d\n",lianjie(a,b));
} //粘贴
int main(void){
	char a[100];
	printf("请输入字符串a:\n");
	gets(a);
	char b[100];
	printf("请输入字符串b:\n");
	gets(b);
	My_srtcmp(a,b);

}
