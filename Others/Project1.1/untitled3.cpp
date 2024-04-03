#include<iostream>
using namespace std;
int main()
{
	int k;
	int n[100008];
	int max;
	int sum = 0;
	cin>>k;
	for(int i = 0;i<k;i++)
	{
		cin>>n[i];
	}
	max = n[0];
	for(int i = 0;i<k;i++)
	{
		sum+=n[i];
		if(sum>max)
		{
			max = sum;
		}
		else if(sum<0)
		{
			sum = 0;
		}
	}
	cout<<max<<endl;
	return 0;
}
