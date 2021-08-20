#include<bits/stdc++.h>
using namespace std;

int OtoDeci(int num)
{
    int sum =0;
    int i=0;
    while(num>0)
    {
        int last = num%10;
        sum += last*pow(8,i);
        i++;
        num = num/10;
    }
    return sum;
}
int main()
{
    int a;
    cin>>a;
    cout<<OtoDeci(a)<<endl;
    return 0;
}
