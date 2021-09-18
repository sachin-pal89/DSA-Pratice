#include<bits/stdc++.h>
using namespace std;

void subq(string input,string output)
{
    if(input.length()==0)
    {
        cout<<output<<endl;
        return;
    }

    subq(input.substr(1),output);
    subq(input.substr(1),output + input[0]);
}

int main()
{
    string input;
    cin>> input;

    string output ="";

    subq(input,output);
    return 0;
}