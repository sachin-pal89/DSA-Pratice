/*
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : 1. The order of strings are not important.
2. Input and output has already been managed for you. 
You just have to populate the output array and return the count of elements populated in the output array.

Input Format :
Integer n
Output Format :
All possible strings in different lines

Constraints :
1 <= n <= 10^6

Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
*/

#include <iostream>
#include <string>
using namespace std;

string Code(int n)
{
   switch(n)
   {
        case 2:
           return "abc";
           break;
        case 3:
           return "def";
           break;
        case 4:
           return "ghi";
           break;
        case 5:
           return "jkl";
           break;
        case 6:
           return "mno";
           break;
        case 7:
           return "pqrs";
           break;
        case 8:
           return "tuv";
           break;
        case 9:
           return "wxyz";
           break;
        default :
           return "";
           break;
   }
}

int keypad(int num, string output[])
{
    if(num==0 || num==1)
      { 
          output[0]=" ";
          return 1;
      }
    
    int x = num%10;
    string c = Code(x);
    int len = c.length();

    int ans = keypad(num/10,output);

    for(int i=0;i<(ans*(len-1));i++)
    {
        output[i+ans] = output[i];
    }

    for(int i=0;i<len;i++)
    {
        for(int j=(i*ans);j<(ans*(i+1));j++)
        {
            output[j] += c[i] ;
        }
    }

    return (ans*len) ;
}

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}