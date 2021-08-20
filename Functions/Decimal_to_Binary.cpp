#include<iostream>
#include<cmath>
using namespace std;

void Bina(int a1)
{
int num =0;
int i=0;
    while(a1>0)
    {   
        int last = a1%2;
        num += last*pow(10,i);
        i++;
        a1 = a1/2;
    }
    cout<<"Binary is "<<num<<endl;
}
int main()
{
    int n;
    cin>>n;
    Bina(n);
    return 0;
}

