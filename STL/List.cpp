#include<iostream>
#include<list>
using namespace std;

void Enter_ele(list<int> &l1)
{   
    list<int> :: iterator it;
    it = l1.begin();
    int ele=0;
    cout<<"\nEnter the element in a list\n";
    for(it = l1.begin(); it != l1.end(); it++)
    {
        cin>>*it;
    }
}

void display(list<int> &l1)
{
    list<int> :: iterator it;
    it = l1.begin();
    for(it = l1.begin();it != l1.end();it++)
    {
        cout<<*it<<" ";
    }
}
int main()
{
    list<int> l1(10);
    Enter_ele(l1);
    display(l1);

    int ele;
    cout<<"\nEnter the element to be removed\n";
    cin>>ele;
    l1.remove(ele);
    display(l1);

    cout<<"\nSorted list is\n";
    l1.sort();
    display(l1);

    cout<<"\nList in reverse order is\n";
    l1.reverse();
    display(l1);

    return 0;
}