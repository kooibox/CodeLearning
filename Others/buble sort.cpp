//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int arr[9] = {2,4,5,1,6,7,8,9,3};
//	int temp;
//	
//	cout << "排序前的结果：" <<endl;
//	for(int i = 0;i<9;i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//	
//	for(int i = 0;i < 9 - 1;i++)
//	{
//		for(int j = 0;j < 9-i-1;j++)
//			if(arr[j] > arr[j + 1])
//			{
//				int temp = arr[j];
//				arr[j] = arr[j+1];
//				arr[j+1] = temp;
//			}
//	}
//	cout << "排序后的结果：" << endl;
//	for(int i = 0;i<9;i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//}

#include<iostream>
using namespace std;

int main()
{
	int arr[]={};
	int temp;
	int num;
	
	cout <<"请输入数字个数："<<endl;
	cin >> num;
	
	arr[num]={};
	
	cout <<"请输入数字：" << endl;
	for(int i=0;i<num;i++){
		cin >> arr[i];
	}
	
	for(int i = 0;i < num - 1;i++)
	{
		for(int j = 0;j < num -i - 1;j++)
			if(arr[j] > arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
	}
	
	cout << "排序后的结果：" << endl;
	for(int i = 0;i < num;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
