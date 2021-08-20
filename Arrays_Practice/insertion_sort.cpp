#include<bits/stdc++.h>
using namespace std;


void seta(int a[],int n)
{
    cout<<"\nEnter the element in array\n";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
}

void Insertionsort(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
        int key = a[i];
        int j = i-1;
        while(j>=0 && a[j]>key)
        {
            a[j+1] = a[j];
            j = j-1;
        }
        a[j+1] = key;
    }
}

void geta(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}

int main()
{
    int n;
    cout<<"\nEnter the length of the array\n";
    cin>>n;

    int a[n];
    seta(a,n);

    Insertionsort(a,n);

    geta(a,n);
    return 0;
}