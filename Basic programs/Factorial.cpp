#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int product=n;
    while(n>1)
    { 
      n--;
      product *= n;
    }

    cout<<"The Factorial is "<<product<<endl;
    return 0;
}