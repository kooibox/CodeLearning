#include<stdio.h>
int main()
{
	int arr[10] = { 10,9,8,7,6,11,4,3,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);//计算出数组元素个数
	int i = 0;
	printf("排序前的数组:");
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	printf("排序后的数组:");
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}