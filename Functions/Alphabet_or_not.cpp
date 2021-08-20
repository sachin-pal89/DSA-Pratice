#include<iostream>
using namespace std;

bool alpha(char c)
{
    int num = int(c);
    if((num>64 && num<91) || (num>96 && num<123))
    {
        return 1;
    }
    return 0;
}
int main()
{
    char ch;
    cin>>ch;

    if(alpha(ch))
    {
        cout<<"It's a Alphabet"<<endl;
    }
    else{
        cout<<"It's Not a Alphabet"<<endl;
    }
    return 0;
}