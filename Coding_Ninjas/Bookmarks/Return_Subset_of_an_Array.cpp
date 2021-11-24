/*
Given an integer array (of length n), find and return all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. 
But the order of elements should remain same as in the input array.
Note : The order of subsets are not important.

Input format :

Line 1 : Size of array

Line 2 : Array elements (separated by space)

Sample Input:
3
15 20 12
Sample Output:
[] (this just represents an empty array, don't worry about the square brackets)
12 
20 
20 12 
15 
15 12 
15 20 
15 20 12 
*/

#include<iostream>
using namespace std;

int subset(int input[],int length, int output[3500][20])
{
   if(length == 0)
   {
       output[0][0] = 0;
       return 1;
   }

   int size = subset(input+1,length-1,output);
   int x = size;

   for(int i=size; i<(2*size); i++)
   {
       output[i][1] = input[0];
       output[i][0] = output[i-size][0] + 1;
       x++;
   }

   for(int i=0; i<size; i++)
   {
       for(int j=1; j<output[i+size][0]; j++)
       {
           output[i+size][j+1] = output[i][j];
       }
   }


   return x;
}

int main()
{
    int input[20],length,output[3500][20];

    cin>>length;

    for(int i=0; i<length; i++)
    {
        cin>>input[i];
    }

    int size = subset(input,length,output);

    for(int i=0; i<size; i++)
    {
        for(int j=1; j<=output[i][0]; j++)
        {
             cout<<output[i][j]<<" ";
        }
        cout<<endl;
    }
}