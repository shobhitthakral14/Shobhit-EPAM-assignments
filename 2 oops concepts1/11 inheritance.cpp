// Inheritance is one of the core concepts of Object-Oriented Programming (OOP) that allows a class (called derived class)
// to inherit properties (data members) and behaviors (member functions) from another class (called base class).

// This promotes code reuse, hierarchical classifications, and polymorphism.

// class Base {
//     // base class members
// };

// class Derived : access_specifier Base {
    // derived class members
// };


// it can be private protected public 


// PUBLIC INHERITANCE 

class Base {
public:
    int pub_var;
protected:
    int prot_var;                                       // PUBLIC INHERITANCE MEANS IS A RELATIONSHIP  THE DERIVED CLASS IS A FORM OF BASE 
private:
    int priv_var;
};

class Derived : public Base {
    // pub_var is public in Derived
    // prot_var is protected in Derived
    // priv_var is NOT accessible in Derived
};


// PRIVATE INHERITANCE 

class Derived : protected Base {
    // pub_var becomes protected in Derived
    // prot_var stays protected in Derived                       // has-a" relationship — they hide the base class interface.
    // priv_var is NOT accessible in Derived
};



// PRIVATE INHERITANCE 

class Derived : private Base {
    // pub_var becomes private in Derived
    // prot_var becomes private in Derived
    // priv_var is NOT accessible in Derived
};






// single inheritance  // class derived : public base;
// multiple inheritance  // class derived : public base1 , public base2 ;





#include <iostream>
using namespace std;

class Animal {
public:
    void sound() {
        cout << "Animal sound" << endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "Dog barks" << endl;
    }
};

int main() {
    Dog d;
    d.sound();  // inherited from Animal
    d.bark();
    return 0;
}




//Inheritance allows runtime polymorphism using virtual functions. 
//The base class declares a function as virtual; derived class overrides it.


// class Base {
// public:
//     virtual void show() {
//         cout << "Base show" << endl;
//     }
// };

// class Derived : public Base {
// public:
//     void show() override {
//         cout << "Derived show" << endl;
//     }
// };

// int main() {
//     Base* ptr = new Derived();
//     ptr->show();  // calls Derived's show() due to virtual function
//     delete ptr;
// }


// it will give compilation error if we don't use virtual and use override 



// Base class constructor is called first, then derived class constructor.

// Destructor calls happen in reverse order: derived class destructor first, then base.





// MULTIPLE INHERTIANCE 


// class A {
// public:
//     void displayA() { cout << "Class A" << endl; }
// };

// class B {
// public:
//     void displayB() { cout << "Class B" << endl; }
// };

// class C : public A, public B {
//     // inherits both A and B
// };

// int main() {
//     C obj;
//     obj.displayA();
//     obj.displayB();
//     return 0;
// }






// AMBIGUITY IN INHERITANCE 
// If two base classes have a function with the same name, the derived class needs to specify which one to call.





// class A {
// public:
//     void display() { cout << "A display" << endl; }
// };

// class B {
// public:
//     void display() { cout << "B display" << endl; }
// };

// class C : public A, public B {
// public:
//     void show() {
//         A::display();  // resolving ambiguity
//         B::display();
//     }
// };

// int main() {
//     C obj;
//     obj.show();
// }





// Constructors are not inherited (only in C++11 with using can you inherit constructors explicitly).




// FUNCTION HIDING 

class Base {
public:
    void func(int x);
};
class Derived : public Base {
public:
    void func(double y)  ; // Hides Base::func(int)
};




//If base class function is not virtual:
//No dynamic dispatch → base version is called.





//Final keyword in inheritance
// Prevents further overriding of virtual functions or inheritance from a class.

class Base {
  virtual void foo() final; // Cannot override in derived
};

class FinalClass final { }; // Cannot be inherited










// Using keyword in inheritance
// Used to:

// Inherit constructors

// Unhide base class functions


// using Base::func;     // Unhide
// using Base::Base;     // Inherit constructor (C++11+)








// DIAMOND PROBLEM 


//The diamond problem occurs in multiple inheritance when a class inherits from two classes that have a common base class.

#include <iostream>
using namespace std;

class A {
public:
    void show() {
        cout << "Class A" << endl;
    }
};

class B : public A {};
class C : public A {};

// D inherits from both B and C
class D : public B, public C {};

int main() {
    D obj;
    // obj.show(); ❌ Ambiguous!
}

// D inherits show() from both B and C.

// So D has two copies of A, causing ambiguity:


// solution

class A {
public:
    void show() { cout << "Class A" << endl; }
};

class B : virtual public A {};
class C : virtual public A {};

class D : public B, public C {};

int main() {
    D obj;
    obj.show(); // ✅ Unambiguous
}


// using virtual inheritance 

// in this constructor of A is constructed only once due to virtual inheritance 







// class A {
// public:
//     A(int x) { cout << "A " << x << "\n"; }
// };

// class B : virtual public A {
// public:
//     B() : A(10) {}  // Won't call A(10), ignored
// };

// class C : virtual public A {
// public:
//     C() : A(20) {}  // Ignored too
// };

// class D : public B, public C {
// public:
//     D() : A(99), B(), C() {}
// };

// int main() {
//     D obj;
// }



// in virtual inheritance the most derived class is responsible for intitalizing the virtual base
//Only A(99) is called.


