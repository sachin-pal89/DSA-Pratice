#include<iostream>
using namespace std;

template <typename T, typename V>

class Pair
{
    T x;
    V y;

public:
    
    void setX(T x)
    {
        this-> x = x;
    }

    T getX()
    {
        return x;
    }
    
    void setY(V y)
    {
        this-> y = y;
    }

    V getY()
    {
        return y;
    }
};

int main()
{   
    // Normal template class
    Pair<int,double> p1;
    p1.setX(10);
    p1.setY(22.3);

    cout<<p1.getX()<<" "<<p1.getY()<<endl;

    // Nested template class
    Pair<Pair<int,double>,char> p2;

    p2.setY('A');

    Pair<int,double> p21;
    p21.setX(100);
    p21.setY(220.3);

    p2.setX(p21);

    cout<<p2.getX().getX()<<" "<<p2.getX().getY()<<" "<<p2.getY()<<endl;

    return 0;
}
