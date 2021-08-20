#include<iostream>
using namespace std;

bool elig(int a)
{
    if(a==18 || a>18)
    {
        return 1;
    }
    return 0;
}
int main()
{
    int age;
    cout<<"Enter age"<<endl;
    cin>>age;
    if(elig(age)){
        cout<<"Can Vote"<<endl;
    }
    else{
        cout<<"Can't Vote"<<endl;
    }
    return 0;
}