#include<bits/stdc++.h>
using namespace std;

// We can also use binary search for searching element and deleting it in a sorted array
int LinSear(int a[],int n,int key)
{
    int x=-1;
    for(int i=0;i<n-1;i++)
    {
        if(a[i]==key)
        {
            x = i;
            break;
        }
    }
    return x;
}

int Del(int a[],int n,int key,int cap)
{    
    if(n>cap)
    {
      cout<<"More element than capacity \n";
      return n;
    }
    
    int l;
    l=LinSear(a,n,key);
    if(l==-1)
    {
        cout<<"\nElement not found \n";
        return n;
    }
    else{
        for(int i=l;i<n;i++)
        {
            a[i] = a[i+1];
        }
        return n-1;
    }
}

int main()
{
    int cap,key,n;
    cout<<"\nEnter Capacity of Array ";
    cin>> cap;
    cout<<"\nEnter the element to be deleted ";
    cin>>key;
    cout<<"\nEnter No.of elemnts present in array ";
    cin>>n;

    int a[cap];
    cout<<"\nEnter the element of array ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    cout<<"\nBefore Deletion \n";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";

    cout<<"\nAfter Deletion \n";
    int x;
    x = Del(a,n,key,cap);
    for(int i=0;i<x;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0; 
}