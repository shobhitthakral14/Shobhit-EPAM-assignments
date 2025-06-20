// Polymorphism means many forms. In C++, it allows objects of different classes to be treated through a common interface, 
// //especially through base class pointers or references. 
// //It is a key pillar of Object-Oriented Programming (OOP) along with encapsulation and inheritance.

// | Type                      | Description                                                                          | Example                                                   |
// | ------------------------- | ------------------------------------------------------------------------------------ | --------------------------------------------------------- |
// | **Compile-time (Static)** | Function/Operator overloading. Resolved at **compile time**.                         | `int add(int, int)` and `float add(float, float)`         |
// | **Runtime (Dynamic)**     | Function overriding using **virtual functions**. Resolved at **runtime** via vtable. | `virtual void draw()` in base class overridden in derived |



// 🔹 1. Compile-Time Polymorphism
// 🔸 a) Function Overloading
// Multiple functions with the same name but different parameter types or counts.


#include<iostream>
using namespace std;

class Base{
    public:
    int add(int x,int y)
    {
        return x+y;
    }
    int add(int x ,int y ,int z)
    {
        return x+y+z;
    }
    float add( float x ,float y)
    {
        return x+y;
    }
    float add(float x, float y ,float z)
    {
        return x+y+z;
    }
};


int main()
{
    Base obj;
    float a=10;
    float b=10.909;
    cout<<obj.add(a,b);

}


// ❌ What You CANNOT Do
// Only changing return type is not enough:

// int add(int a, int b);
// float add(int a, int b); // ❌ Error!


// OVERLOADING MAIN FUNCTION


#include <iostream>
#include <list>
#include <string>
using namespace std;

class calculator{

    public :
    
    int main(int s)
    {
        cout<<s<<endl;
        return 0;
    }

    int main(int a ,int b)
    {
        cout<<a <<" "<<b<<endl;
        return 0;
    }

    int main(char *s)
    {
        cout<<s<<endl;
        return 0;
    }
};

int main()
{
    calculator calc;
    calc.main(4);
    calc.main(5,4);
    calc.main("hello");
}

// as the main not the reserved keyword in cpp we can overload it  