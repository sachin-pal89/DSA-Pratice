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

void Swap(int *x,int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}


void Bubblesort(int a[],int n)
{   
    int swapped = false;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<(n-1-i);j++)
        {
            if(a[j]>a[j+1])
            {  
               swapped = true;
               Swap(&a[j],&a[j+1]);
            }
        }
        
         if(swapped == false)
            {
                break;
            }
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
    cout<<"\nEnter the lenght of array\n";
    cin>>n;

    int a[n];
    seta(a,n);

    Bubblesort(a,n);

    geta(a,n);
    return 0;
}