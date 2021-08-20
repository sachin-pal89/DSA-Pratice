#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    int i;
    int sum =0;
    cin>>n;
    cout<<sizeof(n)<<endl;
    for(i=0;i<sizeof(n);i++)
    {
        int remain =  (n % 10);
        sum += remain*pow(2, i);
        n = n/10;
    }
    cout<<sum<<endl;
    return 0;
}