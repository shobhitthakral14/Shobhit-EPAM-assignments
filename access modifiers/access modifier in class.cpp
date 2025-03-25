#include<iostream>
using namespace std;

//Access modifiers are used to implement an important aspect of Object-Oriented Programming known as Data Hiding.

// By default every data member is private in class 

// Public members are accessible from any part of the program and acessible by other class and functions and accessed using . operator


// Private members hide internal details and prevent direct modification.
// class members declared as private are aceesible to the member functions inside the class 

// Protected is accessible inside the class and derived (child) classes but not outside.

//   Use private for data hiding (Encapsulation).
//   Use public for functions and attributes that need external access.
//   Use protected for inheritance-based access control.

class base{
    int x;

    protected:
    int y;

    public:
    int z;

    void showpublic()
    {
        cout<<"This is showing public data member : "<< z <<endl;
    }

    // acessing indirectly using the public member function of the class 

    void setprivate(int X)
    {
        x=X;
    }

    void showprivate()

    {
        cout<<"This is showing private data member : "<< x <<endl;
    }
};

    class derived : public base{
        public :
        void showprotected(int Y)
        {
            y=Y;
            cout<<"This is showing protected data member : "<<y<<endl;
        }
    };

int main()
{
    base b;
    b.z=20;
    b.showpublic();

    base bt;
    bt.setprivate(40);
    bt.showprivate();

    derived d;
    d.showprotected(50);

    return 0;
}