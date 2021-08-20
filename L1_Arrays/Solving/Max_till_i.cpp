#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"\nEnter the length of array ";
    cin>>n;

    int a[n];
    cout<<"\nEnter element of array ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    int maxi = a[0];
    for(int i=0;i<n;i++)
    {
        maxi = max(maxi,a[i]);
        cout<<maxi<<" ";
    }

    return 0;
}