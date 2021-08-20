#include<bits/stdc++.h>
using namespace std;

void seta(int a[],int n)
{
    cout<<"\nEnter the elements of array\n";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
}
    //for finding gcd
    int gcd(int a,int b)
    {
        if(b==0)
        {
            return a;
        }
        else
        {
            return gcd(b,a%b);
        }
    }

    //Rotating array
    void Rotate(int a[],int n,int d)
    {
        d = d % n;
        int GCD = gcd(d,n);
        for(int i=0;i<GCD;i++)
        {
            int temp = a[i];
            int j=i;

            while(1)
            {
                int k=j+d;
                if(k>=n)
                {
                    k = k - n;
                }
                
                if(k==i)
                {
                    break;
                }

                a[j] = a[k];
                j = k;
            }

            a[j] = temp;
        }
    }

    void print(int a[],int n)
    {   
        for(int i=0;i<n;i++)
        {
        cout<<a[i]<<" ";
        }
    }

    int main()
    {
        int n,d;
        cout<<"Enter the length of array\n";
        cin>>n;

        int a[n];
        seta(a,n);

        cout<<"\nHow many times you wanted to rotate the array\n";
        cin>>d;
        
        Rotate(a,n,d);
        print(a,n);
        return 0;
    }