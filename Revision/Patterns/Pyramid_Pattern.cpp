#include<bits/stdc++.h>
using namespace std;

// Code for half pyramid
void HPyr(int r,int c)
{
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            if(i>=j)
            {
                cout<<"* ";
            }
        }
        cout<<"\n";
    }
}

// Code for Inverted Half Pyramid
void IHPyr(int r,int c)
{
    for(int i=1;i<=r;i++)
    {
        for(int j=c+1-i;j>0;j--)
        {
            cout<<"* ";
        }
        cout<<"\n";
    }
}

// Code for Hollow Inverted Half Pyramid
void HIHPyr(int r,int c)
{   
    int pr=0,j=0;
    for(int i=1;i<=r;i++)
    {   
        for( j=1;j<=r-i+1;j++)
        {
            if(i==1 || i== r-1)
            { cout<<"* ";}
            else{
                if(j==1 || j==r-i+1)
                {
                    cout<<"* ";
                }
                else{
                    cout<<"  ";
                }
            }
        }
        cout<<"\n";
    }
}

// Code for full pyramid
void FPyr(int r,int c)
{
     for(int i=1;i<=r;i++)
    {
        for(int j=c+1-i;j>0;j--)
        {
            cout<<"  ";
        }
        
        for(int k=i;k>0;k--)
        {
            cout<<"*   ";
        }
        cout<<"\n";
    }
}

// Code for Inverted full pyramid
void IFPyr(int r,int c)
{
     for(int i=6;i>0;i--)
    {
        for(int j=1;j<c-i+1;j++)
        {
            cout<<"  ";
        }
        
        for(int k=i;k>0;k--)
        {
            cout<<"*   ";
        }
        cout<<"\n";
    }
}

// Code for Hollow full pyramid
void HFPyr(int r,int c)
{
    int pr=0;
     for(int i=1;i<=r;i++)
    {
        for(int j=c+1-i;j>0;j--)
        {
            cout<<"  ";
        }
        
        for(int k=i;k>0;k--)
        {    
            if(i<=2 || i==r)
            {cout<<"*   ";}

            else{
                if(k<pr && k!= 1)
                {
                    cout<<"    ";
                }
                else{
                    cout<<"*   ";
                }
            }
            pr = k;
        }
        cout<<"\n";
    }
}
int main()
{
    int r,c;
    cout<<"\nEnter rows and column \n";
    cin>>r>>c;
    cout<<"\n";

    HPyr(r,c);
    cout<<"\n";  
    IHPyr(r,c);
    cout<<"\n";
    HIHPyr(r,c);
    cout<<"\n";
    FPyr(r,c);
    cout<<"\n";
    IFPyr(r,c);
    cout<<"\n";
    HFPyr(r,c);
    cout<<"\n";

    return 0;
}