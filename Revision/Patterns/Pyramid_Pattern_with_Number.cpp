#include<bits/stdc++.h>
using namespace std;

// Code for half pyramid
void HPyrN(int r,int c)
{
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<j<<" ";
        }
        cout<<"\n";
    }
}

// Code for Inverted Half pyramid
void IHPyrN(int r,int c)
{
    for(int i=r;i>0;i--)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<j<<" ";
        }
        cout<<"\n";
    }
}

// Code for Hollow Half pyramid
void HHPyrN(int r,int c)
{
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(i<=2 || i==r)
            {
                cout<<j<<" ";
            }
            else{
                if(j==1 || j==i)
                {
                    cout<<j<<" ";
                }
                else{
                    cout<<"  ";
                }
            }
        }
        cout<<"\n";
    }
}

// Code for Full Pyramid
void FPyrN(int r,int c)
{   
    int x=0;
    for(int i=1;i<=r;i++)
    {   
        x=i;
        for(int j=r-i;j>0;j--)
        {
            cout<<"  ";
        }

        for(int k=i;k>0;k--)
        {
            cout<<x<<" ";
            x++;
        }
        
        x--;
        for(int l=i-1;l>0;l--)
        {   
            --x;
            cout<<x<<" ";
        }

        cout<<"\n";
    }
}

// Code for Hollow Full Pyramid
void HFPyrN(int r,int c)
{
      for(int i=1;i<=r;i++)
      {
          for(int j=r-i;j>0;j--)
          {
              cout<<"  ";
          }

          for(int k=1;k<=i;k++)
          {
              if(i<=2 || i==r)
              {
                  cout<<k<<"   ";
              }
              else{
                  if(k==1 || k==i)
                  {
                      cout<<k<<"   ";
                  }
                  else{
                      cout<<"    ";
                  }
              }
          }
          cout<<"\n";
      }
}

// Code of Hollow Inverted Half Pyramid
void HIHPyrN(int r,int c)
{
    for(int i=1;i<=r;i++)
    {
        for(int j=i;j<=r;j++)
        {
            if(i==1 || i>=r-1)
            {
                cout<<j<<" ";
            }
            
            else{
                if(j==i || j==r)
                {
                    cout<<j<<" ";
                }
                else{
                    cout<<"  ";
                }
            }
        }
        cout<<"\n";
    }
}

int main()
{
    int r,c;
    cout<<"\nEnter rows and columns \n";
    cin>>r>>c;
    cout<<"\n";

    HPyrN(r,c);
    cout<<"\n";
    IHPyrN(r,c);
    cout<<"\n";
    HHPyrN(r,c);
    cout<<"\n";
    FPyrN(r,c);
    cout<<"\n";
    HFPyrN(r,c);
    cout<<"\n";
    HIHPyrN(r,c);
    cout<<"\n";

    return 0;
}