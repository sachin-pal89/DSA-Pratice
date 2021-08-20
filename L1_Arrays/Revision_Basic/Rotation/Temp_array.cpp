#include<bits/stdc++.h>
using namespace std;

// Code for rotating array using temp array 
void TempRot(int a[],int n,int d)
{
    int temp[d];
    for(int i=0;i<d;i++)
    {
        temp[i] = a[i];
    }
    
    for(int i=d;i<n;i++)
    {
        a[i-d] = a[i];
    }
    
    int x=0;
    for(int i=n-d;i<n;i++,x++)
    {
        a[i] = temp[x];
    }

}

void print(int a[],int n)
{   
    cout<<"\n";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}

int main()
{
    int n,d;
    cout<<"\nEnter length of an array ";
    cin>>n;

    int a[n];
    cout<<"\nEnter the element of array ";
    for(int i=0;i<n;i++)
    cin>>a[i];

    cout<<"\nEnter how many time to rotate the array ";
    cin>>d;

    TempRot(a,n,d);
    print(a,n);
    return 0;
}