#include<iostream>
using namespace std;

int Max(int a1,int a2,int a3)
{
    if(a1>a2)
    {
        if(a1>a3)
        {
            return a1;
        }
        else{
            return a3;
        }
    }
    else if(a2>a3){
        return a2;
    }
    else{
       return a3;
    }
}

int Mini(int b1,int b2,int b3)
{
    if(b1<b2)
    {
        if(b1<b3)
        {
            return b1;
        }
        else{
            return b3;
        }
    }
    else if(b2<b3){
        return b2;
    }
    else{
       return b3;
    }
}
int main()
{
    int a,b,c;
    cin>>a>>b>>c;

    cout<<"Maximum Value is "<<Max(a,b,c)<<endl;
    cout<<"\nMinimum Value is "<<Mini(a,b,c)<<endl;

    return 0;
}