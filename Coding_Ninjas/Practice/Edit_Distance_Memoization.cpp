#include <cstring>
#include<climits>
#include <iostream>
using namespace std;

// Memoization Approach

int Distance(string s1, string s2, int **output)
{
    
   //Base Case
    if(s1.size() == 0 || s2.size() == 0)
    {
        return s1.size() + s2.size();
    }
    
    int m = s1.size();
    int n = s2.size();
    
    // If the Distance is already present for current situation
    if(output[m][n] != -1)
    {
        return output[m][n];
    }
    
    int ans;
    
    // If the first element of current string is same
    if(s1[0] == s2[0])
    {
         ans = Distance(s1.substr(1),s2.substr(1),output);
    }
    else
    {
        // To get the Distance from all three operation we perform to get the similar string
        
        // Insertion operation
        int insertOP = Distance(s1.substr(1),s2,output);
        
        // Deletion Operation
        int deleteOP = Distance(s1,s2.substr(1),output);
        
        // Updation Operation
        int updateOP = Distance(s1.substr(1), s2.substr(1), output);
        
        ans = 1 + min(insertOP, min(deleteOP, updateOP));
    }
    
    // To store the answer in record for future use
    output[m][n] = ans;
    
    // Return the Minimum distance from this point
    return ans;
}


int editDistance(string s1, string s2)
{
	int m = s1.size();
    int n = s2.size();
    
    int **output = new int*[m+1];
    
    for(int i = 0; i <= m; i++)
    {
        output[i] = new int[n+1];
        
        for(int j = 0; j <= n; j++)
        {
            output[i][j] = -1;
        }
    }
    
    return Distance(s1,s2,output);
}

int main() {
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout << editDistance(s1, s2);
}