#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int main()
{
    // Intializing an unordered map
    unordered_map<string,int> mapping;

   // Pair to insert int hashmap
   pair<string,int> p("sachin",18);
   mapping.insert(p);

   // Insertion through [] brackets
   mapping["anjali"] = 14;

   // To get size of our hashmap
   cout<<"Size of HashMap is "<<mapping.size()<<endl;

   // Accessing the element in HashMap
   cout<<"Sachin : "<<mapping.at("sachin")<<endl;
   cout<<"Anjali : "<<mapping.at("anjali")<<endl;

   // To delete an element from Hashmap
   mapping.erase("anjali");

   // To check if an the particular key is present or not
   if(mapping.count("anjali") > 0)
   {
       cout<<"Anjali is present "<<endl;
   }
   else{
       cout<<"Anjali is not present "<<endl;
   }
   
   // Adding sample elements
   mapping["Sushma"] = 42;
   mapping["Chandev"] = 46;

   // Using iterator to traverse in map && setting it at begining of map
   unordered_map<string,int> :: iterator it = mapping.begin();

   // Printing all element with there key values present in map
   while(it != mapping.end())
   {
       cout<<"Name: "<<it->first<<" Age: "<<it->second<<endl;
       it++;
   }

   // To find a value in map
   if(mapping.find("Chandev") != mapping.end())
   {
       cout<<"Chandev Found"<<endl;
   }
   else{
       cout<<"Not present"<<endl;
   }
   
   return 0;
}