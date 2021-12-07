/*
Given an integer array A of size N, check if the input array can be splitted in two parts such that -
- Sum of both parts is equal
- All elements in the input, which are divisible by 5 should be in same group.
- All elements in the input, which are divisible by 3 (but not divisible by 5) should be in other group.
- Elements which are neither divisible by 5 nor by 3, can be put in any group.

Groups can be made with any set of elements, i.e. elements need not to be continuous.
And you need to consider each and every element of input array in some group.
Return true, if array can be split according to the above rules, else return false.

Note : You will get marks only if all the test cases are passed.
Input Format :
Line 1 : Integer N (size of array)
Line 2 : Array A elements (separated by space)
Output Format :
true or false

Constraints :
1 <= N <= 50

Sample Input 1 :
2
1 2
Sample Output 1 :
false
Sample Input 2 :
3
1 4 3
Sample Output 2 :
true
*/

#include <iostream>
using namespace std;

bool helpersplit(int a[], int n, int lsum, int rsum)
{
    // Once we had traversed all element in array we check id left sum == right sum or not
    if (n == 0)
    {
        if (lsum == rsum)
        {
            return true;
        }
        return false;
    }

    // Number which are divisible by 5
    if (a[0] % 5 == 0)
    {
        return helpersplit(a + 1, n - 1, lsum + a[0], rsum);
    }
    // Number which are divisible by 3 but not divisble by 5
    else if (a[0] % 3 == 0)
    {
        return helpersplit(a + 1, n - 1, lsum, rsum + a[0]);
    }

    // Number which are not divisible by both 3 and 5
    return helpersplit(a + 1, n - 1, lsum + a[0], rsum) || helpersplit(a + 1, n - 1, lsum, rsum + a[0]);
}

bool splitArraySize(int a[], int n)
{
    // If array is emepty then it is balanced
    if (n == 0)
    {
        return true;
    }

    return helpersplit(a, n, 0, 0);
}

int main()
{
    int size;
    cin >> size;

    int *a = new int[1 + size];

    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }

    // To check can we divide the array in given fashion

    if (splitArraySize(a, size))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}