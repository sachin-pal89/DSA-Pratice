#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Time Complextiy :- O(LogN)
vector<char> removeDuplicates(char* arr, int size)
{
    vector<char> ans;
    unordered_map<char,bool> mapping;

    // To check if element is repeated or not and if not then inserting it in vector ans
    for(int i = 0; i < size ; i++)
    {
        // this to check if char is already present or not
        if(mapping.count(arr[i]) > 0 )
        {
           continue;
        }
        else
        {
            // If not then push it in vector and set its status as true in HashMap
            mapping[arr[i]] = true;
            ans.push_back(arr[i]);
        }
    }

    return ans;
}

int main()
{
    char a[] = {'a','a','b','z','a','c','b','n','q'};

    vector<char> ans = removeDuplicates(a,9);
    
    // Display The vector with distinct values
    for(int i=0; i< ans.size() ; i++)
    {
        cout<<ans[i]<<" ";
    }

    return 0;
}