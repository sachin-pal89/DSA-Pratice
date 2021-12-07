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
#include<string>
using namespace std;

int getCodes(string input, string output[])
{
    if(input[0] == '\0')
   {
       output[0] = " ";
       return 1;
   }

   // Including only single value
   int onei = input[0] - 48;                                                
   char firstc = onei + 'a' - 1;
 
   string s1[1000];
   string s2[1000];
   char secc;
   int row1, row2 = 0;

   row1 = getCodes(input.substr(1),s1);
   
   if(input[1] != '\0')
   {
       // Including starting two index element of string
      int seci = (onei*10) + (input[1] - 48);
      secc = seci + 'a' - 1;
   
   if(seci >= 11 && seci <= 26)
   {
       row2 = getCodes(input.substr(2),s2);
   }
   }

   int k = 0;
   for(int i = 0; i < row1; i++)
   {
       output[k] = firstc + s1[i];
       k++;
   }

   for(int i = 0; i < row2; i++)
   {
       output[k] = secc + s2[i];
       k++;
   }

   return k; 
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