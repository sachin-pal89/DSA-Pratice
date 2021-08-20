#include<bits/stdc++.h>
using namespace std;

int main()
{
	int r1,c1,r2,c2;
	cout<<"\nEnter the no.of rows & column in first matrix: ";
	cin>>r1>>c1;
        
	int a[r1][c1];
	cout<<"\nEnter the elements of first matrix: \n";
	for(int i=0;i<r1;i++)
	{
		for(int j=0;j<c1;j++)
		{
			cin>>a[i][j];
		}
	}


	cout<<"\nEnter the no.of rows & column in second matrix: ";
	cin>>r2>>c2;

	int b[r2][c2];
	cout<<"\nEnter the element of second matrix: \n";
	for(int i=0;i<r2;i++)
	{
		for(int j=0;j<c2;j++)
		{
			cin>>b[i][j];
		}
	}

        int ans[r1][c2];
	for(int i=0;i<r1;i++)
	{
		for(int j=0;j<c2;j++)
		{
			ans[i][j]=0;
		}
	}


	// Matrix Multiplication
	
	for(int i=0;i<r1;i++)
	{
		for(int j=0;j<c2;j++)
		{
			for(int k=0;k<c1;k++)
			{
				ans[i][j] += a[i][k] * b[k][j];
                         }
		}
	}
        

	// Multiplied matrix is 
	
	cout<<"\nMultiplication of matrices is: \n";

	for(int i=0;i<r1;i++)
	{
		for(int j=0;j<c2;j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<"\n";
	}

	return 0;
}


                          
