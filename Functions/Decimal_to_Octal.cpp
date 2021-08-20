#include<bits/stdc++.h>
using namespace std;

int Oct(int num)
{
    int sum =0;
    int i =0;
    while(num>0)
    {
        int last = num%8;
        sum += last*pow(10,i);
        i++;
        num = num/8;
    }
    return sum;
}
int main()
{
    int n;
    cin>>n;
    cout<<Oct(n)<<endl;
    return 0;
}