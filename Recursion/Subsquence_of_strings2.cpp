#include<bits/stdc++.h>
using namespace std;

void subq(string input,string output)
{   
     if(input.empty())
     {
         cout<<output<<endl;
         return;
     }

     subq(input.substr(1),output);
     subq(input.substr(1),output + input[0]);
     return;
}

int main()
{
    string input;
    cin>> input;

    string output =" ";

    subq(input,output);
    return 0;
}