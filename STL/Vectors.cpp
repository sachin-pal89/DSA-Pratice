#include<iostream>
#include<vector>
using namespace std;

void Enter_ele(vector<int> &v1)
{
    int ele;
    cout<<"\nEnter the element in vector array\n";
    for(int i = 0 ;i < v1.size(); i++)
    {
        cin>>v1[i];
    }
}

void display(vector<int> &v1)
{
    vector<int> :: iterator it;
    int ele;
    cout<<"\nElement in vector array is\n";
    for(it = v1.begin();it != v1.end();it++)
    {
        cout<<*it<<" ";
    }
}

int main()
{
    vector<int> v1(10);
    Enter_ele(v1);
    display(v1);
    
    int ind,ele;
    cout<<"\nEnter the index and element to be inserted\n";
    cin>>ind>>ele;

    vector<int> :: iterator i = v1.begin();
    v1.insert(i+ind,ele);
    display(v1);
    
    int pos;
    cout<<"\nEnter the position to check the element\n";
    cin>>pos;
    cout<<v1.at(pos)<<"\n";

    int start,end;
    cout<<"\nEnter the starting and ending index between which element is to be deleted\n";
    cin>>start>>end;
    v1.erase(i+start,i+end);
    display(v1);

    return 0;
}