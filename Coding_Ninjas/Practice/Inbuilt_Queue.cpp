#include<iostream>
#include<queue>
using namespace std;

int main()
{
    queue<char> q;

    q.push('A');
    q.push('B');
    q.push('C');
    q.push('D');
    q.push('E');
    q.push('F');

    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;

    cout<<q.empty()<<endl;
    cout<<q.size()<<endl;
    
    // To display element of queue
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    
    return 0;
}