
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int r,c;
	cout<<"\nEnter the no.of rows and column in 2D Arrays: ";
	cin>>r>>c;

	int a[r][c];
	cout<<"\nEnter the elements of 2D arrays: \n";

	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cin>>a[i][j];
		}
	}

	cout<<"\nThe given 2D array is: \n";
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}

	return 0;
}

