#include<iostream>
using namespace std;

int sum(int num)
{
    int s =0;
    for(int i=1;i<=num;i++)   //OR      // s= (num*(num+1))/2;
    {
        s += i;                         //  return s; 
    }
    return s;
}
int main()
{
    int n;
    cin>>n;
    cout<<sum(n)<<endl;
    return 0;
}