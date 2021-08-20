#include<bits/stdc++.h>
using namespace std;

int HDtoDeci(string num)
{
    int sum =0;
    int x = 0;
    int len = num.size();
    for(int i=len-1;i>=0;i--)
    {
        if(num[i] >= '0' && num[i] <= '9')
        {
            sum += (num[i]-'0')*pow(16,x);
        }
        else if(num[i] >= 'A' && num[i] <= 'F')
        {
            sum += (num[i]-'A'+10)*pow(16,x);
        }
        x++;
    }
    return sum;
}
int main()
{
    string n;
    cin>>n;
    cout<<HDtoDeci(n)<<endl;
    return 0;
}