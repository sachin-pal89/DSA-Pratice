
#include<bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	cout<<"\nEnter a string: ";
	getline(cin,str);

	int freq[26];
	for(int i=0;i<26;i++)
	   freq[i]=0;


	for(int i=0;i<str.length();i++)
	   freq[str[i]-'a']++;


	int count=0;
	char ans='a';
	   
	for(int i=0;i<26;i++)
	{
		if(freq[i] >= count)
		{
			count = freq[i];
			ans = i + 'a';
		}
	}

	cout<<"\nMaximum Frequency is: "<<count<<"\n";
	cout<<"\nCharacter with maximum frequency is: "<<ans<<"\n";

	return 0;
}

