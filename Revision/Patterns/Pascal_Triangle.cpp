#include<bits/stdc++.h>
using namespace std;

int fact(int n)
{
    if(n<=1)
    {
        return 1;
    }
    else{
        return n*fact(n-1);
    }
}

int Combi(int a,int b)
{
    int Re=0;
    Re= fact(a)/(fact(b)*fact(a-b));
    return Re;
}

void Pascal(int r)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<=i;j++)
        {
              cout<<Combi(i,j)<<" ";
        }
        cout<<"\n";
    }
}

int main()
{
    int r;
    cout<<"\nEnter No.of Rows \n";
    cin>>r;

    Pascal(r);
    return 0;
}