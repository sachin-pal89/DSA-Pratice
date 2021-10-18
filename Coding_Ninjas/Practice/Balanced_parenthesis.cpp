#include<iostream>
#include<stack>
using namespace std;

stack<char> s;
bool isBalanced(string ex)
{   
    if(ex.empty())
    {
        if(s.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    if(ex[0]==')' && s.empty())
    {
        return false;
    }

    if(ex[0]=='(')
    {
        s.push('(');
    }

    if(ex[0]==')')
    {
        if(s.top() == '(')
        {
            s.pop();
        }
    }

    return isBalanced(ex.substr(1));
}

int main() 
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}