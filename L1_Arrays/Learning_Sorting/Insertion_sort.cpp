#include<bits/stdc++.h>
using namespace std;

// Code for Insertion swap
void InsertionSort(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
        int j = i-1;
        int x = a[i];

        while(j>=0 && a[j] > x)
        {
            a[i] = a[j];
            j--;
        }
        a[j+1] = x;
    }
}

void print(int a[],int n)
{
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
}

int main()
{
    int n;
    cout<<"\nEnter the length of an array ";
    cin>>n;

    int a[n];
    cout<<"\nEnter the element of an array ";
    for(int i=0;i<n;i++)
    cin>>a[i];

    InsertionSort(a,n);
    cout<<"\nArray after sorting ";
    print(a,n);

    return 0;
}