#include<iostream>
using namespace std;

int fact(int num){
    int facto=1;
    for(int i=2;i<=num;i++){
        facto *=i;
    }
    return facto;
}
int main()
{
    int n;
    cin>>n;

    cout<<"Factorial is "<<fact(n)<<endl;
    return 0;
}