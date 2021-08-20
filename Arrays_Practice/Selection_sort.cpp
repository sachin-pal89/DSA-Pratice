#include<bits/stdc++.h>
using namespace std;

void seta(int a[],int n)
{
    cout<<"\nEnter the element in the array\n";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
}

void Swap(int *x,int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void SelectionSort(int a[],int n)
{
    int min;
    for(int i=0;i<n-1;i++)
    {
        min = i;
        for(int j=i+1;j<n;j++)
        {  
           if(a[j]<a[min])
           {   
               min = j;  
           } 
        }
         Swap(&a[min],&a[i]);
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
    cout<<"\nEnter the length of array\n";
    cin>>n;

    int a[n];
    seta(a,n);

    SelectionSort(a,n);

    geta(a,n);
    return 0;
}