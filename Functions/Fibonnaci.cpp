#include<iostream>
using namespace std;

void fibo(int num){
    int num1=0,num2=1;
    int sum;
   
    for(int i=0;i<num;i++)
    {
        cout<<num1<<endl;
        sum = num1 + num2;
        num1 = num2;
        num2 = sum;
    }
}
int main()
{
    int n;
    cin>>n;
    cout<<endl;
    fibo(n);
    return 0;
}