#include<iostream>
using namespace std;

// It provides a more efficient and direct way to initialize class members, particularly when dealing with const members, references, and base class constructors.  

// Without an initialization list, const and references cannot be assigned values inside the constructor body.
class base
{
    int a ;
    const int b;
    int &ref;

    public:
        base(int x,int y): a(x),b(y) ,ref(a)
        {
            cout<<"constructor intitalized "<< a <<" " << b <<" " << ref <<endl;
        }   

        friend ostream& operator<<(ostream &out, const base &obj) {
            out << "Base(" << obj.a << ", " << obj.b << ")";
            return out;
        }
};

class another
{
    // for intitalizing the object of another class 
    base bs;
    public:
    another(int hp ,int bp) :  bs(hp,bp)
    {
        cout<<"another initialized "<< bs <<endl;
    }
};

int  main()
{
    base obj(10,5);
    another an1(500,600);
    return 0;
}