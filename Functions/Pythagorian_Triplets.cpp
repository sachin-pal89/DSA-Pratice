#include<bits/stdc++.h>
using namespace std;

void Triplates(int a,int b,int c)
{
    int maxi = (max(a,max(b,c)));
    int num1,num2;
    if(maxi == a)
    {
            num1 = b;
            num2 = c;
    }
    else if(maxi == b)
    {
        num1 = a;
        num2 = c;
    }
    else{
        num1 = a;
        num2 = b;
    }

    if(maxi*maxi == (num1*num1 + num2*num2))
    {
        cout<<"It's a Pythagorian Triplets "<<endl;
    }
    else{
        cout<<"It's not a Pythagorian Triplets "<<endl;
    }
}
int main()
{
    int x,y,z;
    cin>>x>>y>>z;
    Triplates(x,y,z);
    return 0;
}