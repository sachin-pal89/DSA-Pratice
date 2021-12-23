// Dynamic Approach

#include<iostream>
using namespace std;

int LCS(string s, string t)
{
    int m = s.size();
    int n = t.size();

    int **output = new int*[m+1];

    for(int i = 0; i <= m; i++)
    {
        output[i] = new int[n+1];
    }

    // To fill the rows and column where size of s && t would be 0

    // For all output[0][column]
    for(int j = 0; j <= n; j++)
    {
        output[0][j] = 0;
    }

    // For all output[row][0]
    for(int i = 0; i <= m; i++)
    {
        output[i][0] = 0;
    }

    // To fill all other cases which depends on other
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            // To get subsequence of maximum length from all three cases
            int maxi = max(output[i-1][j-1], max(output[i][j-1], output[i-1][j]));

            // If the current character of both string are same
            if(s[m-i] == t[n-j])
            {
               maxi += 1;
            }
            
            // Storing the maximum subsequence length for this combination of characters
            output[i][j] = maxi;
        }
    }

    return output[m][n];
}

int main()
{
      string s,t;

    cin>>s>>t;

    cout<<"Longest Common Subsequence: "<<LCS(s,t)<<endl;

    return 0;
}