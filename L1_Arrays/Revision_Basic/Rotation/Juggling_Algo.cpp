#include<bits/stdc++.h>
using namespace std;

// Program to find GCD
int GCD(int a,int b)
{
    if(b==0)
    return a;
    
    else
    return GCD(b,a%b);
}

// Code for Rotation
void Rotate(int a[],int n,int d)
{
    d = d%n;   // to adjust if d>=n
    int gcd = GCD(d,n);

    for(int i=0;i<gcd;i++)
    {
        int temp = a[i];
        int j = i;

        while(1){
            int k = j+d;
            if(k>=n)
            {
                k = k-n;
            }

            if(k==i)
            break;

            a[j] = a[k];
            j = k;
        }
        a[j] = temp;
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