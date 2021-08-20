#include<bits/stdc++.h>
using namespace std;

// Code for Swapping
void Swapping(int *x,int *y)
{
     int temp = *x;
     *x = *y;
     *y = temp;

}

// Code for Selection Sort
void SelectionSort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
      int Min = i;
      for(int j=i+1;j<n;j++)
        {
          if(a[Min]>a[j])
          Min = j;
        }
      Swapping(&a[i],&a[Min]);
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
    cout<<"\nEnter the element of the array ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    SelectionSort(a,n);

    cout<<"\nArray After sorting is ";
    print(a,n);

    return 0;
}