#include<iostream>
using namespace std;

class Fraction
{
    private:
        int numerator;
        int denominator;
    
    public:
       
       Fraction(int numerator, int denominator)
       {
           this -> numerator = numerator;
           this -> denominator = denominator;
       }

       void simplify()
       {
             int gcd =1;
             int j = min(numerator, denominator);

             for(int i=1; i<=j ; i++)
             {
                 if(numerator % i == 0 && denominator % i == 0)
                     gcd = i;
             }

             numerator = numerator / gcd;
             denominator /= gcd;
       }

       Fraction operator+(Fraction const &f2) const
       {
           int lcm = denominator * f2.denominator;
           int x = lcm / denominator;
           int y = lcm / f2.denominator;

           int num = x * numerator + (y * f2.numerator);

           Fraction fnew(num,lcm);
           fnew.simplify();
           return fnew;
       }
       
       Fraction operator*(Fraction const &f2) const
       {
           int n = numerator * f2.numerator;
           int d = denominator * f2.denominator;
           
           Fraction fnew(n,d);
           fnew.simplify();
           return fnew;
       }

       bool operator==(Fraction const &f2) const
       {
           return (numerator == f2.numerator && denominator == f2.denominator);      
       }
       
       Fraction operator/(Fraction const &f2) const
       {
           int num = numerator * f2.denominator;
           int denom = denominator * f2.numerator;

           Fraction fnew(num,denom);
           fnew.simplify();
           return fnew;
       }
       
       // Pre Increment
       Fraction& operator++()
       {
           numerator = numerator + denominator;
           simplify();

           return *this;
       }
       
       // Post Increment
       Fraction& operator++(int)
       {
           Fraction fnew(numerator,denominator);
           fnew.simplify();

           numerator = numerator + denominator;
           simplify();

           return fnew;
       }

       Fraction& operator+=(Fraction const &f2)
       {
           int lcm = denominator * f2.denominator;
           int x = lcm / denominator;
           int y = lcm / f2.denominator;

           int num = numerator * x + (y * f2.numerator);
           
           numerator = num;
           denominator = lcm;
           simplify();

           return *this;
       }
       
       Fraction& operator-=(Fraction const &f2)
       {
           int lcm = denominator * f2.denominator;
           int x = lcm / denominator;
           int y = lcm / f2.denominator;

           int num = numerator * x - (y * f2.numerator);
           
           numerator = num;
           denominator = lcm;
           return *this;
       }

       Fraction& operator-(Fraction const &f2)
       {
           int lcm = denominator * f2.denominator;
           int x = lcm / denominator;
           int y = lcm / f2.denominator;

           int num = numerator * x - (y * f2.numerator);
           
           numerator = num;
           denominator = lcm;
           simplify();

           return *this;
       }
    
       // Pre Decrement
       Fraction& operator--()
       {
           numerator = numerator - denominator;
           simplify();

           return *this;
       }

       // Post Decrement
       Fraction& operator--(int)
       {   
           Fraction fnew(numerator,denominator);
           fnew.simplify();

           numerator = numerator - denominator;
           simplify();

           return fnew;
       }

       void print()
       {
           cout<<numerator<<" "<< denominator<<endl;
       }
};

int main()
{   
    Fraction f1(12,7);
    Fraction f2(10,4);
    
    cout<<"First Fraction: "<<endl;
    f1.print();
    cout<<"Second Fraction: "<<endl;
    f2.print();
    
    if(f1==f2)
    {
        cout<<"\nBoth Fractions are equal"<<endl;
    }
    else
    {
        cout<<"\nBoth Fractions have different value"<<endl;
    }

    Fraction f3 = f1 + f2;
    
    cout<<"Addition :"<<endl;
    f3.print();

    Fraction f4 = f1 * f2;

    cout<<"Multiplication :"<<endl;
    f4.print();
   
    Fraction f5 = f1 / f2;

    cout<<"Division :"<<endl;
    f5.print();

    Fraction f6 = ++f1;
    cout<<"Pre Increment of First Fraction: "<<endl;
    f1.print();
    f6.print();
    
    Fraction f7 = ++(++f1);
    cout<<"Nested Pre Increment of First Fraction: "<<endl;
    f1.print();
    f7.print();
    
    cout<<endl;
    return 0;
}