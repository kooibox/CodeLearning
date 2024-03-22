//#include<stdio.h>
//
//void g(int k);
//void f(int *p);
//
//int main(void)
//{
//	int i = 6;
//	printf("&i=%p\n",&i);
//	f(&i);
//	g(i);
//	
//	return 0;
//}
//
//void f(int *p){
//	printf(" p = %p\n",p);
//	printf(" *p = %d\n",*p);
//	*p = 26;
//}
//
//void g(int k){
//	printf(" k = %d",k);
//}

//point
//#include<stdio.h>
//
//void swap(int *pa,int *pb);
//
//int main(void){
//	int a = 5;
//	int b = 6;
//	swap(&a,&b);
//	printf("a=%d,b=%d",a,b);
//	return 0;
//}
//
//void swap(int *pa,int *pb)
//{
//	int t = *pa;
//	*pa = *pb;
//	*pb = t;
//}

#include<stdio.h>

void minmax(int a[],int len,int *max,int *min);

int main(void){
	int a[] = {1,2,3,4,5,6,7,8,9,12,13,14,16,17,21,23,55};
	int min,max;
	printf("main sizof(a)=%lu\n",sizeof(a));
	minmax(a,sizeof(a)/sizeof(a[0]),&min,&max);
	printf("min=%d,max=%d\n",min,max);
	
	return 0;
}

void minmax(int a[],int len,int *min,int *max){
	int i;
	printf("minmax sizof(a)=%lu\n",sizeof(a[]));
	*min = *max = a[0];
	for(i = 1;i < len;i++){
		if(a[i]<*min){
			*min = a[i];
		}
		if(a[i]>*max){
			*max = a[i];
		}
	}
}

//#include<stdio.h>
//
//int divide(int a,int b,int *result);
//
//int main(void)
//{
//	int a = 5;
//	int b = 0;
//	int c;
//	if( divide(a,b,&c)){
//		printf("%d/%d=%d\n",a,b,c);
//	}
//	return 0;
//}
//
//int divide(int a,int b,int *result)
//{
//	int ret = 1;
//	if(b == 0)ret = 0;
//	else{
//		*result = a/b;
//	}
//	return ret;
//}


