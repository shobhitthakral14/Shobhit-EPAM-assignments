// When a base class pointer or reference is used to point to a derived class object,
// and the function to be called is determined based on the actual object type,
// not the pointer/reference type — that's runtime polymorphism.






#include<iostream>
using namespace std;

class base{
    public:
      void display()
     {
        cout<<"this is base class";
     }
};

class derive : public base 
{
    public:  
    void display()
    {
        cout<<"this is derive class";
    }
};

int main()
{
    derive d;
    d.display();
    return 0;
}

// can only write override if the base class function is virtual 






// VIRTUAL FUNCTIONS 


#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() {
        cout << "Base class show()" << endl;
    }
};

class Derived : public Base {
public:
    void show() override {  // overrides Base::show()
        cout << "Derived class show()" << endl;
    }
};

int main() {
    Base* bptr;
    Derived d;
    bptr = &d;
    bptr->show();  // Calls Derived::show() due to virtual function
}



// if we forget virtual base class function will be called 

// override keyword ensure that overriding a base class

// we can override a function with different return type only when their return type are covariant

// #include <iostream>
// using namespace std;

// class Animal {
// public:
//     virtual Animal* clone() {
//         cout << "Cloning Animal\n";
//         return new Animal();
//     }
// };

// class Dog : public Animal {
// public:
//     Dog* clone() override {  // Covariant return: Dog* is derived from Animal*
//         cout << "Cloning Dog\n";
//         return new Dog();
//     }
// };

// int main() {
//     Animal* a = new Dog();
//     Animal* b = a->clone();  // Calls Dog::clone
//     delete a;
//     delete b;
// }
