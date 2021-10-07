#include <vector>
#include <climits>
#include <iostream>
using namespace std;

class Polynomial
{    
    public: 

     int *degCoeff;
     int capacity;

    public:

       Polynomial()
       {
           capacity = 5;
           degCoeff = new int[5];
           for(int i=0;i<capacity;i++)
           {
               degCoeff[i] = 0;
           }
       }

       Polynomial(Polynomial const &p2)
       {
           this -> capacity = p2.capacity;
           this -> degCoeff = new int[capacity];

           for(int i=0;i<capacity;i++)
           {
              degCoeff[i] = p2.degCoeff[i];
           }
       }

       void operator=(Polynomial const &p2)
       {
           this -> capacity = p2.capacity;
           this -> degCoeff = new int[capacity];

           for(int i=0;i<capacity;i++)
           {
               degCoeff[i] = p2.degCoeff[i];
           }
       }

       void setCoefficient(int degree, int coefficient)
       {
           while(degree >= capacity)
           {
               int* arr = new int[2*capacity];

               for(int i=0;i<capacity;i++)
               {
                   arr[i] = degCoeff[i];
               }

               for(int i=capacity; i<(2*capacity);i++)
               {
                   arr[i] = 0;
               }
               
               delete[] degCoeff;
               degCoeff = arr;
               capacity *= 2;
           }

           degCoeff[degree] = coefficient;
       }

       Polynomial operator+(Polynomial &p2)
       {
           int Max = max(capacity, p2.capacity);

           if(Max==capacity)
           {
               for(int i=p2.capacity;i<capacity;i++)
               {
                   p2.setCoefficient(i,0);
               }
           }
           else if(Max==p2.capacity)
           {
               for(int i=capacity;i<p2.capacity;i++)
               {
                   setCoefficient(i,0);
               }
           }

           Polynomial p3;
           for(int i=0;i<Max;i++)
           {
               p3.setCoefficient(i, degCoeff[i] + p2.degCoeff[i]);
           }

           return p3;
       }

       Polynomial operator-(Polynomial &p2)
       {
           int Max = max(capacity, p2.capacity);

           if(Max==capacity)
           {
               for(int i=p2.capacity;i<capacity;i++)
               {
                   p2.setCoefficient(i,0);
               }
           }
           else if(Max==p2.capacity)
           {
               for(int i=capacity;i<p2.capacity;i++)
               {
                   setCoefficient(i,0);
               }
           }

           Polynomial p3;
           for(int i=0;i<Max;i++)
           {
               p3.setCoefficient(i, degCoeff[i] - p2.degCoeff[i]);
           }

           return p3;
       }

       Polynomial operator*(Polynomial &p2)
       {
           Polynomial p3;
           for(int i=0;i<capacity;i++)
           {
               Polynomial p;
               for(int j=0;j<p2.capacity;j++)
               {
                   p.setCoefficient(i+j, degCoeff[i] * p2.degCoeff[j]);
               }
               p3 = p3+p;
           }

           return p3;
       }

       void print()
       {
           for(int i=0;i<capacity;i++)
           {   
               if(degCoeff[i]==0)
               {
                   continue;
               }
               else
               {
               cout<<degCoeff[i]<<"x"<<i<<" ";
               }
           }
           cout<<endl;
       }
};

//Driver program to test above functions
int main()
{
    int count1,count2,choice;
    cin >> count1;
    
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];
    
    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }
    
    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }
    
    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }
    
    cin >> count2;
    
    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];
    
    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }
    
    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }
    
    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }
    
    cin >> choice;
    
    switch(choice){
            // Add
        case 1:
        {
            Polynomial result1 = first + second;
            result1.print();
            break;
        }
            // Subtract
        case 2 :
        {
            Polynomial result2 = first - second;
            result2.print();
            break;
        }
            // Multiply
        case 3 :
        {
            Polynomial result3 = first * second;
            result3.print();
            break;
        }
        case 4 : // Copy constructor
        {
            Polynomial third(first);
            if(third.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            if(fourth.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
    }
    
    return 0;
}