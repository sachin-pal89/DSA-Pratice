#include<iostream>
#include<cmath>
using namespace std;

bool Prime(int num)
{
     for(int i=2;i<=sqrt(num);i++)
     {
          if(num%i==0)
          {
              return 0;
          }
     }
     return 1;
}
int main()
{
    int a,b;
    cin>>a>>b;

    for(int i=a;i<=b;i++){
       if(Prime(i))
       {
           cout<<i<<endl;
       }
    }
    return 0;
}