#include<iostream>
#include<map>
#include<string>
using namespace std;

void display(map<string,int> &sc)
{
     map<string,int> :: iterator it;
    for(it=sc.begin();it!=sc.end();it++)
    {
        cout<<(*it).first<<" "<<(*it).second<<"\n";
    }
}
int main()
{
    map<string,int> score;
    score["Sachin"] = 99;
    score["Roy"] = 78;
    score["Virat"] = 50;
    display(score);
   
    int mar;
    string nam;
    cout<<"\nEnter the name of student and marks obtained by him/her\n ";
    cin>>nam>>mar;
    score.insert({nam,mar});
    display(score);
    
    return 0;
}