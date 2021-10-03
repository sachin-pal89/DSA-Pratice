/*
Sort an array A using Merge Sort.
Change in the input array itself. 
So no need to return or print anything.

Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)

Output format :
Array elements in increasing order (separated by space)

Constraints :
1 <= n <= 10^3

Sample Input 1 :
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8

Sample Input 2 :
5
2 1 5 2 3
Sample Output 2 :
1 2 2 3 5
*/

#include <iostream>
using namespace std;

void merge(int* input,int start,int end)
{
   
    int mid = (start+end)/2;
    int arr[end-start+1];

    int i=start,j=mid+1;
    int z=0;

    while(i<=mid && j<=end)
    {
        if(input[i]<=input[j])
        {
            arr[z] = input[i];
            i++;
            z++;
        }
        else 
        {
            arr[z]= input[j];
            j++;
            z++;
        }
    }

    while(i<=mid)
    {
        arr[z]=input[i];
        i++;
        z++;
    }

    while(j<=end)
    {
        arr[z]=input[j];
        j++;
        z++;
    }
    
    int x=0;
    for(int i=start;i<=end;i++)
    {
        input[i] = arr[x];
        x++;
    }
    return;
}

void sort(int* input,int start, int end)
{   
    if(start>=end)
      return;
    
    int mid = (start+end)/2;

    sort(input,start,mid);
    sort(input,mid+1,end);

    merge(input,start,end);
    return;
}

void mergeSort(int* input,int length)
{
    sort(input,0,length-1);
    return;
}

int main() {
  int length;
  cin >> length;

  int* input = new int[length];

  for(int i=0; i < length; i++)
    cin >> input[i];

  mergeSort(input, length);

  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";

    delete[] input;
  }
}