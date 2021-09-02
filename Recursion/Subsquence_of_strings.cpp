#include<bits/stdc++.h>
using namespace std;

int subq(string input, string output[])
{
    if(input.empty())
       {
           output[0]=" ";
           return 1;
       }
    
    string s = input.substr(1);
    int count= subq(s,output);

    for(int i=0;i<count;i++)
    {
        output[i+count] = input[0] + output[i];
    }

    return 2*count;
}


int main()
{
    string input;
    cin>>input;

    int n= input.length();
    
    int x = pow(2,n);
    string* output = new string[x];
    
    int count= subq(input,output);

    for(int i=0; i<count; i++)
    {
        cout<<output[i]<<endl;
    }
    return 0;
}