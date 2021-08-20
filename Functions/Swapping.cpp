#include<iostream>
using namespace std;

void swapping(int *a1,int *a2)  // by call of pointers
{
    int t = *a1;  // values are interchanged by help of pointers
    *a1 = *a2;
    *a2 = t;
}
int main()
{
    int a,b;
    cout<<"Enter value for a and b "<<endl;
    cin>>a>>b;
    swapping(&a,&b);      // memory address of a,b are sent
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    return 0;
}