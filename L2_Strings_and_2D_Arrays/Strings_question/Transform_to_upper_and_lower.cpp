#include<bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	cout<<"\nEnter the string: ";
	getline(cin,str);

	//Lower case to Upper case
	
	transform(str.begin(),str.end(),str.begin(),::toupper);
        cout<<"\nUpper Case: \n";
	cout<<str<<"\n";

	// Upper case to Lower case
	
	transform(str.begin(),str.end(),str.begin(),::tolower);
        cout<<"\nLower Case: \n";
	cout<<str<<"\n";

	return 0;
}

