// Dynamic Approach

#include<iostream>
#include<cstring>
using namespace std;

// To get the Distance
int editDistance(string s1, string s2)
{
	int m = s1.size();
    int n = s2.size();
    
    // intializing an 2D matrix of size (m+1)*(n+1)
    int **output = new int*[m+1];
    for(int i = 0; i <= m; i++)
    {
        output[i] = new int[n+1];
    }
    
    // To put values at cell where row = 0, Thus the column number would be stored in them
    for(int j = 0; j <= n; j++)
    {
        output[0][j] = j;
    }
    
    // To put values at cell where column = 0, thus the row number would be stored in them
    for(int i = 0; i <= m; i++)
    {
        output[i][0] = i;
    }
    
    // As value in a postion depend upon minimum distance of three adjacent position.
    
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            // If the character of s1 && s2 at this location are same then diatnce is same as of diagonal position
            if(s1[m-i] == s2[n-j])
            {
                output[i][j] = output[i-1][j-1];
            }
            else
            { 
                // We find the position with minimum distance and add 1 since we would consider one best operation
                output[i][j] = 1 + min(output[i-1][j-1], min(output[i-1][j], output[i][j-1]));
            }
        }
    }
    
    // returning the minimum no of operation to make two string equal
    return output[m][n];
}

int main()
{
    string s1, s2;

    cin>>s1;
    cin>>s2;

    cout<<editDistance(s1,s2);
    return 0;
}