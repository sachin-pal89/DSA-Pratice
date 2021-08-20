#include<bits/stdc++.h>
using namespace std;

// Code for Floyd's Triangle Pattern
void Floyd(int r)
{   
    int x=0;
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=i;j++)
        {
            x++;
            cout<<x<<" ";
        }
        cout<<"\n";
    }
}

int main()
{
    int r;
    cout<<"\nEnter No.of rows \n";
    cin>>r;
    cout<<"\n";

    Floyd(r);
    return 0;
}