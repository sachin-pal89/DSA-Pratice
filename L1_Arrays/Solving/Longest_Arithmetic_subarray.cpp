#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"\nEnter the lenght of array ";
    cin>>n;

    int a[n];
    cout<<"\nEnter the element of array ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int j;
    cout<<"\nEnter the ith index from where you want to get the output ";
    cin>>j;

    int pd=a[j-1]-a[j-2];
    int currele = j;
    int ans = j;
    
    while(j<n)
    {
        if(pd==a[j]-a[j-1])
        {
            currele++;
        }
        else{
            pd = a[j]-a[j-1];
            currele = 2;
        }
        ans = max(ans,currele);
        j++;
    }
     
    cout<<ans;
    return 0;
}