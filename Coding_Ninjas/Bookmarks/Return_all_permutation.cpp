/*
Given a string S, find and return all the possible permutations of the input string.

Note 1 : The order of permutations is not important.
Note 2 : If original string contains duplicate characters, permutations will also be duplicates.

Input Format :
String S
Output Format :
All permutations (in different lines)

Sample Input :
abc
Sample Output :
abc
acb
bac
bca
cab
cba
*/
#include<iostream>
#include<string>
using namespace std;

int helper(string input, string output[], int row)
{
    if(input[0] == '\0')
    {
        output[row] = " ";
        return row+1;
    }
    
    for( int i = 0; i < input.length(); i++)
    {
        char ele = input[i];
        string s = input;
        int row1 = helper(s.erase(i,1),output,row);

        for(int i = row ; i < row1; i++)
        {
            output[i] = ele + output[i];
        }
        row = row1;
    }

    return row;
}

int returnPermutation(string input, string output[])
{
    return helper(input,output,0);
}

int main()
{
    string input;
    cin>>input;

    string output[1000];

    int count = returnPermutation(input,output);

    for(int i = 0; i < count; i++)
    {
        cout<<output[i]<<endl;
    }

    return 0;
}