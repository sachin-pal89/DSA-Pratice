#include<bits/stdc++.h>
using namespace std;

// Code for swapping 
void Swapping(int *x,int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Code for Bubble sort
void BubbleSort(int a[],int n)
{
    for(int k=0;k<n;k++)
    {   
        int flag =0;
        for(int i=0;i<n-k-1;i++)
        {
             if(a[i]>a[i+1])
             {
                 Swapping(&a[i],&a[i+1]);
                 flag = 1;
             }
        }

        if(flag == 0)
        break;
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

    BubbleSort(a,n);
    cout<<"\nArray after sorting ";
    print(a,n);

    return 0;
}
