#include <bits/stdc++.h>
using namespace std;

void seta(int a[], int n)
{
    cout << "\nEnter the element of array\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void Merge(int a[], int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = a[low + i];
    }

    for (int j = 0; j < n2; j++)
    {
        R[j] = a[mid + 1 + j];
    }

    int i = 0, j = 0, k = low;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }

        k++;
    }

    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(int a[], int low, int high)
{
    int mid;
    if (low >= high)
    {
        return;
    }

    mid = low + (high - low) / 2;
    MergeSort(a, low, mid);
    MergeSort(a, mid + 1, high);
    Merge(a, low, mid, high);
}

void geta(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    int n;
    cout << "\nEnter the length of array\n";
    cin >> n;

    int a[n];
    seta(a, n);

    MergeSort(a, 0, n - 1);

    geta(a, n);
    return 0;
}