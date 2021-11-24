/*
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. 
You are given a numeric string S. 
Write a program to return the list of all possible codes that can be generated from the given string.

Note : The order of codes are not important. And input string does not contain 0s.

Input format :
A numeric string

Constraints :
1 <= Length of String S <= 10

Sample Input:
1123
Sample Output:
aabc
kbc
alc
aaw
kw
*/

#include<iostream>
#include<string.h>
using namespace std;

int helper(string input, string output[], char ans,int row)
{
    if(input[0] == '\0')
    {
        output[row] = ans;
        return row+1;
    }

    int x = input[0] - 48;
    char c = x - 'a' +1;
    char c1 = '\0';

    int ans1 = helper(input.substr(1),output,c,row);
    
    string s = input.substr(0,2);
    int o = stoi(s);

    if(o > 10 && o < 27)
    {
       c1 = o - 'a' +1;

       int ans2 = helper(input.substr(2),output,c1,ans1);

    }





}

int getCodes(string input, string output[])
{
    char ans;

    return helper(input,output,ans,0);
}

int main()
{
    string input;
    cin>>input;

    string output[10000];

    int count = getCodes(input,output);

    for(int i=0; i<count; i++)
    {
        cout<<output[i]<<endl;
    }

    return 0;
}