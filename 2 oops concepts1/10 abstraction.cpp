//Abstraction is a principle of object-oriented programming (OOP) that hides complex internal implementation and shows only the relevant details to the user.

// eg Think of it like a car — you use the steering wheel and pedals, but don’t need to know how the engine or gearbox works.

// abstraction can be done by 2 ways 
// 1.) abstract class
// 2.) interfaces


//An abstract class is any class that has at least one pure virtual function.

#include <iostream>
using namespace std;

// Abstract class
class Shape {
public:
    virtual void draw() = 0; // Pure virtual function
     Shape()
     {
        cout<<"hello from base constructor"<<endl;
     }
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing Circle\n";
    }
};

class Square : public Shape {
public:
    void draw() override {
        cout << "Drawing Square\n";
    }
};

int main() {
    // here  i am instantiating the derived class and the pointer type is base class pointer as we cannot instantiate the base class as it is abstract 
    Shape* s1 = new Circle();
    Shape* s2 = new Square();
    s1->draw();
    s2->draw();
    return 0;
}

//you must instantiate a derived class that implements all pure virtual functions of the abstract class
// You cannot instantiate an abstract class.
// U can have constructor in abtract class they are use to intialize data members of base class 



////IMP
// if a derived class does not override all pure virtual functions it will become abstract itself and cannot be instantiated  

// class Base {
// public:
//     virtual void func1() = 0;
//     virtual void func2() = 0;
// };

// class Derived : public Base {
// public:
//     void func1() override {
//         std::cout << "func1 overridden\n";
//     }
//     // func2() NOT overridden here
// };

// int main() {
//     // Derived d; // ❌ Compilation error: Derived is still abstract
//     Base* b = new Derived(); // ❌ Can't instantiate Derived either
// }



//2.) Interfaces (a class has all the functions as pure virtual)


class RemoteControl {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
};

class TVRemote : public RemoteControl {
public:
    void turnOn() override {
        cout << "TV is ON\n";
    }
    void turnOff() override {
        cout << "TV is OFF\n";
    }
};





// USES 

// Reduces complexity of the code.

// Improves maintainability and modularity.

// Supports polymorphism.

// Allows you to program to interfaces, not implementation.






// INHERITANCE FROM MULTIPLE ABSTRACT CLASS

// class A { public: virtual void f() = 0; };
// class B { public: virtual void g() = 0; };

// class C : public A, public B {
// public:
//     void f() override {}
//     void g() override {}
// };





// IF UR CLASS HAS DESRTUCTOR MAKE IT VIRTUAL AS IF  Deleting through base pointer delete s; will only call SHAPE DESTRCUTOR ONLY NOT THE CIRCLE
// WHICH LEADS TO RESOURCE LEAKS 

// IF IT HAS VIRTUAL THEN DERIVED IS CALLED FIRST THEN THE BASE CLASS 

//Deleting derived object directly is always safe.

//Deleting through base class pointer requires virtual destructor to be safe.

// class Shape {
// public:
//     ~Shape() { cout << "Shape destructor\n"; }
//     virtual void draw() = 0;
// };

// class Circle : public Shape {
// public:
//     ~Circle() { cout << "Circle destructor\n"; }
//     void draw() override { cout << "Drawing Circle\n"; }
// };

// int main() {
//     Circle* c = new Circle();
//     c->draw();
//     delete c;  // Both Circle and Shape destructors are called here
//     return 0;
// }



// AN ABSTRACT CLASS CAN HAVE DATA MEMBERS , OTHER FUNCTIONS WHICH ARE NOT VIRTUAL , WHICH ARE NOT PURE VIRTUAL ALSO ,

// PURE VIRTUAL FUNCTION CAN HAVE IMPLEMENTATION 

// class Shape {
// public:
//     virtual void draw() = 0;
// };

// void Shape::draw() {
//     cout << "Common part of draw\n";
// }





//Assigning a derived object to a base class by value causes object slicing — the derived part is lost.

// Always use pointers or references to abstract/base class to avoid slicing.

//Circle c;
//Shape s = c;  // Object slicing! Only Shape part copied, Circle part lost




// interface is a class where all functions are pure virtual and usually has no data members,
// whereas abstract classes can have data members and some implemented functions.