#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"\nEnter the length of array ";
    cin>>n;

    int a[n];
    cout<<"\nEnter the element of array ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int sum;
    cout<<"\nSum of subarray ";
    for(int i=0;i<n;i++)
    {   sum = 0;
        for(int j=i;j<n;j++)
        {
            sum += a[j];
            cout<<sum<<" ";
        }
    }

    return 0;
}