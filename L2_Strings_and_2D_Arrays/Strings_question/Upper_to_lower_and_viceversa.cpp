#include<bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	cout<<"\nEnter the string: ";
	getline(cin,str);

	// To convert from lower to upper case
	for(int i=0;i<str.length();i++)
	{
		if(str[i]>= 'a' && str[i]<='z')
		{
			str[i] -= 32;
		}
	}
        
	cout<<"\nUpper Case :\n";
	cout<<str<<"\n";

	//To convert from upper to lower case
	for(int i=0;i<str.length();i++)
	{
		if(str[i]>='A' && str[i]<='Z')
		{
			str[i] += 32;
		}
	}
        
	cout<<"\nLower Case :\n";
	cout<<str<<"\n";

        return 0;
}



