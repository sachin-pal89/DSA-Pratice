#include<bits/stdc++.h>
using namespace std;

// Traversing is simply tracelling and accessing every element of an array
void Travers(int a[],int n)
{
    cout<<"\nElements of array are ";
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
}

int main()
{
    int a[] = {3,4,6,11,90,22};
    cout<<sizeof(a);
    int n = sizeof(a)/sizeof(a[0]);

    Travers(a,n);
    return 0;
}