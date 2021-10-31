#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> v;

    for(int i=0; i<10; i++)
    {
        v.push_back(2*(i+1));
    }

    cout<<"Size of vector is "<<v.size()<<endl;
    cout<<"Element at 5 index of vector is "<<v.at(5)<<endl;


    for(int i=0 ; i<v.size(); i++)
    {
        cout<<v.at(i)<<endl;
    }

    cout<<"After removing last element from vector "<<endl;
    v.pop_back();

    for(int i=0; i<v.size(); i++)
    {
        cout<<v.at(i)<<endl;
    }

    return 0;
}