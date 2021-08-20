#include<bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	cout<<"\nEnter a numeric string: ";
	getline(cin,str);

	//Sorting a numeric string in descending order
	
	sort(str.begin(),str.end(),greater<int>());

	cout<<"\nString in descending order: "<<str<<"\n";

	//Sorting a numeric string in ascending order
	
	sort(str.begin(),str.end());

	cout<<"\nString in ascending order: "<<str<<"\n";

	return 0;
}

