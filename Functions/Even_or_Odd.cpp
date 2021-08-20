#include<iostream>
using namespace std;

bool check(int num)
{
    if(num%2==0){
        return 1;
    }
    return 0;
}

int main()
{
    int n;
    cin>>n;
    
    if(check(n)){
        cout<<"Even"<<endl;
    }
    else{
    cout<<"Odd"<<endl;
    }
    return 0;
}