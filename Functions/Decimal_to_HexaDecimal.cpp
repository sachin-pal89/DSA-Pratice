#include<bits/stdc++.h>
using namespace std;

void Hexa(int num)
{
    string ans = "";
    while(num>0)
    {
        int last = num%16;
        if(last <= 9)
        {
            ans =  ans + to_string(last) ;
        }
        else if(last >= 10 && last <= 15)
        {
              char c = 'A' + last - 10;
              ans.push_back(c);
        }
        num = num/16;   
    }
    int n = ans.size();
    for(int i=n-1;i>=0;i--)
    {
        cout<<ans[i];
    }
}
int main()
{
    int n;
    cin>>n;
    Hexa(n);
    return 0;
}