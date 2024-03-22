#include<iostream>
using namespace std;

void text()
{
    cout << "请输入要计算的阶乘数";
    int n;
    cin >> n;
    int sum = 1,i = 1;
    while (i <= n)
    {
        sum *= i;
        i++;
    }
    cout << n << "! = " << sum << endl;
}

int main(){
    text();
}