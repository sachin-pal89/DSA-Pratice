#include<bits/stdc++.h>
using namespace std;

// Code for Solid Rectangle
void  Srec(int a,int b)
{
    for(int i=1;i<=b;i++)
    {
        for(int j=1;j<=a;j++)
        {
            cout<<"* ";
        }
        cout<<"\n";
    }
}

// Code for Hollow Rectangle
void Hrec(int a,int b)
{
    for (int i = 1; i <=b; i++)
    {
            for(int j=1;j<=a;j++)
            {   
                if(i==1 || i==b)
                  {
                cout<<"* ";
                  }

                else{
                   if( j==1 || j==a)
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

int main()
{
     int l,b;
    cout<<"\nEnter length & breadth of rectangle \n";
    cin>>l>>b;

    Srec(l,b);
    cout<<"\n";
    Hrec(l,b);
    return 0;
}