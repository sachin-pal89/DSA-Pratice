#include<bits/stdc++.h>
using namespace std;

void seta(int a[],int n)
{
    cout<<"\nEnter elements of array\n";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
}

void Reverse(int a[],int start,int end)
{
    while(start<=end)
    {
        int temp = a[start];
        a[start] = a[end-1];
        a[end-1] = temp;
        start++;
        end--;
    }
}

void Rotate(int a[],int n,int d)
{
    d = d % n;
    Reverse(a,0,d);
    Reverse(a,d,n);
    Reverse(a,0,n);
}

void print(int a[],int n)
{   
    for(int i=0;i<n;i++)
    {
    cout<<a[i]<<" ";
    }
}

int main()
{
    int n;
    cout<<"\nEnter the length of array\n";
    cin>>n;

    int a[n];
    seta(a,n);

    int d;
    cout<<"\nHow many times  you need to rotated the array\n";
    cin>>d;

    Rotate(a,n,d);
    print(a,n);

    return 0;
}