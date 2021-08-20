#include<bits/stdc++.h>
using namespace std;

void seta(int a[],int n)
{
    cout<<"\nEnter the element of array\n";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
}

int MaxP(int a[],int n)
{
    int buy,sell;
    buy=0;
    sell=0;
    
    for(int i=0;i<n;i++)
    {
        if(a[i]<a[i-1])
        {
            buy = a[i];
            sell = a[i];
        }
        else if(a[i]<a[i+1])
        {
            sell = a[i+1];
        }
    }
    int profit = sell-buy;
    return profit;
}
int main()
{
    int n;
    cout<<"\nEnter the length of an array\n";
    cin>>n;

    int a[n];
    seta(a,n);

    cout<<"\nMaxium Profit earned would be "<<MaxP(a,n);
    return 0;
}