#include<bits/stdc++.h>
using namespace std;

// Code for single rotation of array 
void RotateOne(int a[],int n)
{
    int temp;
    temp = a[0];

    for(int i=0;i<n-1;i++)
    {
        a[i] = a[i+1];
    }
    a[n-1] = temp;
}

// Code for Rotating multiple time using RotateOne()
void Rotate(int a[],int n,int d)
{
      for(int i=0;i<d;i++)
      {
          RotateOne(a,n);
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
    int n;
    cout<<"\nEnter No.of Elements in an array ";
    cin>>n;

    int a[n];
    cout<<"\nEnter the element of array ";
    for(int i=0;i<n;i++)
    cin>>a[i];
    
    int d;
    cout<<"\nEnter how many times to rotate the array ";
    cin>>d;

    Rotate(a,n,d);
    print(a,n);
    return 0;
}