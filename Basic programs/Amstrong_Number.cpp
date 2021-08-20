#include<iostream>
#include<cmath>
using namespace std;

// amstrong number e.g  153 
// 1^3 + 5^3 + 3^3 = 1+125+27 = 153 
// Thus 153 is amstrong number

int main()
{
    int n;
    cin>>n;
    int sum=0;
    int org=n;

    while(n>0)
    {
        int last = n % 10;
        sum += pow(last,3);
        n = n/10;
    }

    if(org==sum)
    {
        cout<<"Amstrong number"<<endl;
    }
    else
    {
        cout<<"Non-Amstrong number"<<endl;
    }
    return 0;
}