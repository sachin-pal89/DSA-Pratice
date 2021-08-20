#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"\nEnter the length of array ";
    cin>>n;

    int a[n+1];
    a[n]= -1;

    cout<<"\nEnter the element of array ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int maxi=-1;
    int ans =0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>maxi && a[i]>a[i+1])
        {
            ans++;
        }

        maxi = max(maxi,a[i]);
    }

    cout<<ans<<"\n";
    return 0;
}