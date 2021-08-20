// formula of nCr =   n!/(n-r)!*r!
#include<iostream>
using namespace std;

int facto(int num)
{
    int product = 1;
    for(int i=2;i<=num;i++)
    {
        product *= i;
    }
    return product;
}
int main()
{
    int n,r;
    cin>>n>>r;

    int Value = facto(n)/(facto(r)*facto(n-r));
    cout<<Value<<endl;

    return 0;
}