#include <cstring>
#include <iostream>
using namespace std;

// Dynamic Programming approach

int knapsack(int* weight, int* value, int n, int maxWeight)
{
    // Creating an (n+1)*(maxWeight+1) matrix
    int **output = new int*[n+1];
    for(int i = 0; i <= n; i++)
    {
        output[i] = new int[maxWeight + 1];
    }

    // All case where n == 0 would have 0 value
    for(int j = 0; j <= maxWeight; j++)
    {
        output[0][j] = 0;
    }

    // All case where maxWeight == 0 the value would also be 0
    for(int i = 0; i <= n; i++)
    {
        output[i][0] = 0;
    }

    // To fill the required value in cell
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= maxWeight; j++)
        {
            // If the weight of current index is greater than j(current maxWeight)
            if(weight[i-1] > j)
            {
                output[i][j] = output[i-1][j];
            }
            else
            {
                output[i][j] = max(output[i-1][j], (output[i-1][j-weight[i-1]] + value[i-1]));
            }
        }
    }

    return output[n][maxWeight];
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