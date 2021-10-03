#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

int pairsum(int *arr,int i,int j,int num)
{
    int k=0;
    while(i<j)
    {
        if(arr[i]+arr[j]>num)
           j--;
        
        else if(arr[i]+arr[j]<num)
           i++;
        
        else
        {
            if(arr[i]==arr[j])
            {
                int h=j-i;
                k = h*(h+1)/(2+k);
                i++;
                j--;
            }
            else
            {
                int a=1,b=1;
                while(arr[i]==arr[i+1])
                  a++; i++;
                while(arr[j]==arr[j-1])
                  b++; j--;
                
                k = a*b+k;
                i++;
                j--;
            }
        }
    }
    return k;
}

int tripletSum(int *arr, int n, int num)
{
    int ans =0;

    for(int i=0;i<n-2;i++)
    {
        ans += pairsum(arr,i+1,n-1,num-arr[i]);
    }

    return ans;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int size;
		int x;
		cin >> size;

		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}
		cin >> x;

		cout << tripletSum(input, size, x) << endl;

		delete[] input;
	}

	return 0;
}
