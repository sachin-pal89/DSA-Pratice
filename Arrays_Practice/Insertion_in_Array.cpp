#include <bits/stdc++.h>
using namespace std;

void seta(int a[], int m)
{
    cout << "\nEnter the element of an array " << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
}

int Insert(int a[], int m, int ele, int ind, int n)
{   // Insertion

    for (int i = m - 1; i >= ind; i--)
    {
        a[i + 1] = a[i];
    }
    a[ind] = ele;
    return 1;
}

int Insert2(int a[], int m, int ele, int ind, int n)
{   // Insertion without order

    int temp = a[ind];
    a[ind] = ele;
    a[m] = temp;

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
    cout << "Enter the Length of Array " << endl;
    cin >> n;
    cout << "How many elements are already their in an array " << endl;
    cin >> m;
    if (m >= n)
    {
        cout << "\nCannot Inserted " << endl;
    }
    else
    {   
        int a[n];
        seta(a, m);
        int ele, ind;
        cout << "\nEnter the element to be inserted " << endl;
        cin >> ele;
        cout << "\nEnter the index at which to be inserted " << endl;
        cin >> ind;
        
        if(ind > n){
        int x;
        cout<<"\nFor Insertion - 1.Maintain order  2.Not Maintain order "<<endl;
        cin>>x;
        
        if(x==1)
        {
        if (Insert(a, m, ele, ind, n))
        {
            cout << "\nExecuted " << endl;
            m += 1;
            geta(a, m);
        }
        }
        else if(x==2)
        {
            if(Insert2(a,m,ele,ind,n))
            {
                cout<<"\nExecuted "<<endl;
                m +=1;
                geta(a,m);
            }
        }
        else{
            cout<<"\nChoose a Valid option "<<endl;
        }
        }

        else{
            cout<<"Cannot Insert \n";
        }
    }

    return 0;
}