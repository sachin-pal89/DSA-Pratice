#include<bits/stdc++.h>
using namespace std;

int main()
{
   int n;
   cout<<"Enter size of array\n";
   cin>>n;
   
   int a[n];
   int p[n];
   cout<<"\nGive element of array\n";
   for(int i=1;i<=n;i++)
   {
      cin>>a[i];
      p[i] = p[i-1] + a[i];
   } 

   int q;
   cout<<"\nHow many quries\n";
   cin>>q;
   while(q--)
   {  
      int l,r;
      cin>>l>>r;
      cout<< p[r]-p[l-1]<<endl;
   }
   return 0;
}