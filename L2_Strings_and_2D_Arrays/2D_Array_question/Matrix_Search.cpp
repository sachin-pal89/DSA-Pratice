
// In this program matrix have rows and column elements in ascending order

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int r,c;
	cout<<"\nEnter no.of rows & column in an given matrix: ";
	cin>>r>>c;
        
	int a[r][c];
	cout<<"\nEnter the elements of array: \n";
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cin>>a[i][j];
		}
	}
        
	int ele,counter=0;
	cout<<"\nEnter the elemnet to be found: ";
	cin>>ele;

	//Matrix search
	
        int n=0,m=c-1;
	while( n<r && m>=0)
	{
		if(a[n][m]==ele)
			counter=1;

		if(a[n][m]>ele)
			m--;

		else
			n++;
	}

	if(counter)
		cout<<"\nElement founded in matrix ";
	else
		cout<<"\nElement not present in the matrix ";


	return 0;
}

