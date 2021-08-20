#include<bits/stdc++.h>
using namespace std;

void swap(int *a,int *b)
{    
     int temp = *a;
     *a=*b;
     *b=temp;
}


int main()
{
	int r,c;
	cout<<"\nEnter no.of rows & column: ";
	cin>>r>>c;
        
	int a[r][c];
	cout<<"\nEnter the elements of 2D array: \n";
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cin>>a[i][j];
		}
	}


	//Transpose of the given matrix
	
	for(int i=0;i<r;i++)
	{
		for(int j=i;j<c;j++)
		{
			swap(&a[i][j],&a[j][i]);
		}
	}

        cout<<"\nTranspose of given matrix is: \n";
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


