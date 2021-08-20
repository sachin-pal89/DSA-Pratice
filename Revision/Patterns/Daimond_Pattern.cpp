#include<bits/stdc++.h>
using namespace std;

// Code for Solid Diamond
void SDia(int r)
{
    int c = r/2;
    for(int i=1;i<=c;i++)
    {
        for(int j=(c-i);j>0;j--)
        {
            cout<<"  ";
        }

        for(int k=1;k<=i;k++)
        {
            cout<<"*   ";
        }
        cout<<"\n";
    }
    
    for(int i=c;i>0;i--)
    {
        for(int j=(c-i);j>0;j--)
        {
            cout<<"  ";
        }

        for(int k=1;k<=i;k++)
        {
            cout<<"*   ";
        }
        cout<<"\n";
    }

}

// Code for Hollow Daimond
void HDia(int r)
{
    int c = r/2;
    for(int i=1;i<=c;i++)
    {
        for(int j=(c-i);j>0;j--)
        {
            cout<<"  ";
        }

        for(int k=1;k<=i;k++)
        {   
            if(i<=2)
            cout<<"*   ";

            else{
                if(k==1 || k==i)
                {
                    cout<<"*   ";
                }
                else{
                    cout<<"    ";
                }
            }
        }
        cout<<"\n";
    }
    
    for(int i=c;i>0;i--)
    {
        for(int j=(c-i);j>0;j--)
        {
            cout<<"  ";
        }

        for(int k=1;k<=i;k++)
        {   
            if(i<=2)
            cout<<"*   ";

            else{
                if(k==1 || k==i)
                {
                    cout<<"*   ";
                }
                else{
                    cout<<"    ";
                }
            }
        }
        cout<<"\n";
    }

}

//Code for Solid Half Diamond
void SHDia(int r)
{   
    int mid = (r/2);
    for(int i=1;i<=(r/2);i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<"* ";
        }
        cout<<"\n";
    }

    for(int i=mid+1;i>0;i--)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<"* ";
        }
        cout<<"\n";
    }

}

int main()
{
    int r;
    cout<<"\nEnter the no.of layers in diamond \n";
    cin>>r;
    cout<<"\n";

    SDia(r);
    cout<<"\n";
    HDia(r);
    cout<<"\n";
    SHDia(r);

    return 0;
}