#include<bits/stdc++.h>
using namespace std;

// code for reversing an array
void ReverseArr(int a[],int x,int y)
{
       for(int i=x;i<y;i++,y--)
       {
            int temp = a[i];
            a[i] = a[y];
            a[y] = temp;
       }
}

// Code for rotation
void Rotate(int a[],int n,int d)
{
    if(d==0)
    return;

    d = d%n;

    ReverseArr(a,0,d-1);
    ReverseArr(a,d,n-1);
    ReverseArr(a,0,n-1);
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