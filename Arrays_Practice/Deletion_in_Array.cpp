#include <bits/stdc++.h>
using namespace std;

void seta(int a[], int m)
{
    cout << "\nEnter the element of array " << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
}

int Delete(int a[], int m, int ind)
{
        for (int i = ind; i < m-1; i++)
        {
            a[i] = a[i + 1];
        }
        return 1;
}


int Delete2(int a[], int m, int ind)
{
        a[ind] = a[m-1];
        a[m-1] = a[m];
        return 1;
}

void geta(int a[], int m)
{
    for (int i = 0; i < m; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n, m;
    cout << "\nEnter the length of array " << endl;
    cin >> n;
    cout << "\nEnter the number of elements in the array " << endl;
    cin >> m;

    if (m > n)
    {
        cout << "\nCannot Delete " << endl;
    }
    else
    {
        int ind;
        int a[n];
        seta(a, m);
        cout << "\nEnter the index value of the element that is to be removed " << endl;
        cin >> ind;

        if (ind > (m - 1))
        {
            cout << "\nCannot delete " << endl;
        }
        else
        {   
            int x;
            cout<<"\nFor Deletion - 1.Maintain Order  2.Not Maintain Order "<<endl;
            cin>>x;
            if(x==1){
            if (Delete(a, m, ind))
            {
                cout << "\nDeletion Successful " << endl;
                m -= 1;
                geta(a, m);
            }
            }
            else if(x==2)
            {
                if(Delete2(a,m,ind))
                {
                    cout<<"\nDeletion Successful "<<endl;
                    m -= 1;
                    geta(a,m);
                }
            }
            else
            {
                cout<<"\nChoose valid option"<<endl;
            }
        }
    }
    return 0;
}