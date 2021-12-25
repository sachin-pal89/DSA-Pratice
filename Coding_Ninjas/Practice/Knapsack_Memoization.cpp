#include <cstring>
#include <iostream>
using namespace std;

// memoization approach

int knap(int* weight, int* value, int n, int maxWeight, int **output)
{
    // Base Case
    if(n == 0 || maxWeight == 0)
    {
        return 0;
    }
    
    // If we have the max value for given maxWeight and index
    if(output[n][maxWeight] != -1)
    {
        return output[n][maxWeight];
    }
    
    int ans;
    
    // If our current weight is more than the current capacity of knapsack
    if(weight[0] > maxWeight)
    {
        ans = knap(weight+1, value+1, n-1, maxWeight, output);
    }
    else
    {
        int x = knap(weight+1, value+1, n-1, maxWeight - weight[0], output) + value[0];
        
        int y = knap(weight+1, value+1, n-1, maxWeight, output);
        
        ans = max(x,y);
    }
    
    // saving it for future record
    output[n][maxWeight] = ans;
    
    return ans;
}

int knapsack(int* weight, int* value, int n, int maxWeight) {
	
    int **output = new int*[n+1];
    
    for(int i = 0; i <= n; i++)
    {
        output[i] = new int[maxWeight+1];
        
        for(int j = 0; j <= maxWeight; j++)
        {
            output[i][j] = -1;
        }
    }
    
    return knap(weight,value,n,maxWeight,output);

}

int main() {
    int n;
    cin >> n;
    int* wt = new int[n];
    int* val = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    for (int j = 0; j < n; j++) {
        cin >> val[j];
    }

    int w;
    cin >> w;

    cout << knapsack(wt, val, n, w) << "\n";

    delete[] wt;
    delete[] val;
}