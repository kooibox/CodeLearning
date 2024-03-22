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
//
//#include<stdio.h>
//
//void minmax(int a[],int len,int *max,int *min);
//
//int main(void){
//	int a[] = {1,2,3,4,5,6,7,8,9,12,13,14,16,17,21,23,55};
//	int min,max;
//	printf("main sizof(a)=%lu\n",sizeof(a));
//	minmax(a,sizeof(a)/sizeof(a[0]),&min,&max);
//	printf("min=%d,max=%d\n",min,max);
//	
//	return 0;
//}
//
//void minmax(int a[],int len,int *min,int *max){
//	int i;
//	printf("minmax sizof(a)=%lu\n",sizeof(a[]));
//	*min = *max = a[0];
//	for(i = 1;i < len;i++){
//		if(a[i]<*min){
//			*min = a[i];
//		}
//		if(a[i]>*max){
//			*max = a[i];
//		}
//	}
//}

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

//#include <stdio.h>
//
//double P( int n, double x );
//
//int main()
//{
//	int n;
//	double x;
//	
//	scanf("%d %lf", &n, &x);
//	printf("%.2f\n", P(n,x));
//	
//	return 0;
//}
//
///* 你的代码将被嵌在这里 */
//double P(int n,double x)
//{
//	if(n == 0){
//		return 1.0;
//	}
//	if(n == x){
//		return 0;
//	}
//	if(n > 1){
//	}
//}
//#include<stdlib.h>
//#include<stdio.h>
//
//int main()
//{
//	int num = 0;
//	int size = 0;
//	int ret = 0;
////	size = sizeof(size)/sizeof(int); 
//	scanf("%d",&size);
//	scanf("%d",&num);
//	
//	int arry[size];
//	for(int i=0;i<size;i++){
//		scanf("%d",&arry[i]);
//	}
//	for(int i=0;i<size;i++){
//		if(num == arry[i]){
//			ret = i;
//			break;
//		if(num == size-1){
//			ret = 0;
//		}
//		}
//	}
//	if(ret == 0){
//		printf("Not Found");
//	}else if(ret != 0){
//		printf("%d",ret);
//	}
//}
//#include<stdio.h>
//
//int main(){
//	int n;
//	scanf("%d",&n);
//	int arry[n];
//	
//	for(int i=n-1;i>=0;i--){
//		scanf("%d",&arry[i]);
//	}
//	for(int i=0;i<n;i++){
//		printf("%d ",arry[i]);
//	}
//	
//}

//#include<stdio.h>
//int main()
//{
//	int n,i,a[10];
//	scanf("%d\n",&n);
//	for(i=0;i<n;i++){
//		scanf("%d",&a[i]);
//	}
//	
//	for(int x=1;x<=n-1;x++)
//	{
//		int temp;
//		for(i=x;i<=n-1;i++)
//		{
//			if(a[i]>a[x-1])
//			{
//				temp = a[x-1];
//				a[x-1] = a[i];
//				a[i] = temp;
//				
//			}
//		}
//	}
//	
//	
//	printf("%d", a[0]);
//	for(i=1; i<n; i++)
//		printf(" %d", a[i]);
//	return 0;
//	
//	
//}

//#include<stdio.h>
//
//int main()
//{
//	int n;
//	scanf("%d",&n);
//	int a[10],i,min,max;
//	for(i=0;i<n;i++)scanf("%d",&a[i]);
//	for(i=0,min=0;i<n;i++)//找出最大与最小值所在位置 
//	{
//		if(a[min]>a[i])
//			min=i;
//	}
//	int b = a[0];
//	a[0] = a[min];
//	a[min] = b;        //数组b用于交换
//	
//	for(i=0,max=0;i<n;i++)
//		if(a[max]<a[i])
//			max=i;
//	
//	b = a[max];
//	a[max] = a[n-1];
//	a[n-1] = b;
//	
//	for(i=0;i<n;i++)
//		printf("%d ",a[i]);
//}

//#include <stdio.h>
//int main(){
//	int arr[10],n,m,i;
//	scanf("%d",&n);
//	for(  i=0;i<n;i++){
//		scanf("%d",&arr[i]);
//	}
//	scanf("%d",&m);
//	//以上是简单的输入；
//	for(i=0;i<n;i++){
//		if(m<arr[i]){
//			for(int j=n;j>i;j--){
//				arr[j]=arr[j-1];//找到位置，将后面的往后推一个单位。
//			}
//			break;
//		}
//	}
//	arr[i]=m;//赋值；
//	for( i=0;i<n+1;i++){
//		printf("%d ",arr[i]);//输出；
//	}
//	return 0;
//}


