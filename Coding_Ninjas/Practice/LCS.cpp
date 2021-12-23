// Memoization approach

#include<iostream>
using namespace std;

int LCS_mem(string s, string t, int **output)
{
    // To save the current size of string
    int m = s.size();
    int n = t.size();

    // Base Case
    if(s.size() == 0 || t.size() == 0)
    {
        return 0;
    }
    
    // If LCS is known for this condition
    if(output[m][n] != -1)
    {
        return output[m][n];
    }

    int ans;

    // If first character is same
    if(s[0] == t[0])
    {
        ans = 1 + LCS_mem(s.substr(1),t.substr(1),output);
    }
    else
    {
         // Removing first element of s and getting LCS in remaining string
         int a = LCS_mem(s.substr(1),t,output);

         // Removing first element of t and getting LCS in remaining string
         int b = LCS_mem(s,t.substr(1),output);

         // Removing first element of both string and get LCS
         int c = LCS_mem(s.substr(1),t.substr(1),output);

         ans = max(a,max(b,c));
    }

    // To save it in record for future use
    output[m][n] = ans;

    return ans;
}

int LCS(string s, string t)
{
    int m = s.size();
    int n = t.size();

    int **output = new int*[m+1];

    for(int i = 0; i <= m; i++)
    {
        output[i] = new int[n+1];
        for(int j = 0; j <= n; j++)
        {
            output[i][j] = -1;
        }
    }

    return LCS_mem(s,t,output);
}

int main()
{
    string s,t;

    cin>>s>>t;

    cout<<"Longest Common Subsequence: "<<LCS(s,t)<<endl;

    return 0;
}