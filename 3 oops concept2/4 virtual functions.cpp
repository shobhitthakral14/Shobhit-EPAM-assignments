#include<iostream>
using namespace std;

class Animal {
public:
    virtual void sound() {  // virtual function
        cout << "Animal sound" << endl;
    }
};

class Dog : public Animal {
public:
    void sound() override {  // function overriding
        cout << "Bark" << endl;
    }
};

int main() {
//   Animal * an ;
//   Dog d;
//   an=&d;
//   an->sound();

// ALLOCATING DYNAMICALLY IN HEAP
Animal* an = new Dog();
an->sound();   // Output: Bark
delete an;     // ✅ Required!

  return 0;

}




// VIRTUAL DESTRUCTOR 

class Base {
public:
    virtual ~Base() { cout << "Base Destructor" << endl; }
};

class Derived : public Base {
public:
    ~Derived() { cout << "Derived Destructor" << endl; }
};

int main() {
    Base* b = new Derived();
    delete b; // Both destructors will be called
}




// 🔸 How It Works Internally (vtable mechanism)
// Each class with virtual functions has its own vtable (array of function pointers).

// Each object of that class stores a vptr, which points to the class’s vtable.

// When a virtual function is called using a base pointer/reference, vptr is used to resolve the function at runtime.

// 🔸 Important Points
// Virtual functions enable dynamic dispatch.

// If the function is not virtual, the base class function will always be called (no polymorphism).

// Destructors should be virtual in base classes when dealing with inheritance to avoid resource leaks.

// A class with at least one virtual function is called a polymorphic class.





// FINAL KEYWORD USE TO PREVEND FURTHER OVERRIDING 




// Can we override a non-virtual function?
// Yes, but it won't be polymorphic—base pointer will still call base version.




//The C++ language uses Vtable and Vptr to manage virtual functions.


// A virtual function is a member function that is declared within a base class with the virtual keyword and is re-defined (Overridden) by a derived class.
// When a class contains a virtual function, it can be overridden in its derived class and tells the compiler to perform dynamic linkage (or late binding) on the function.
// Now, the virtual functions are implemented in C++ by using vTable and vPtr.


// //The vTable, or Virtual Table, is a table of function pointers that is created by the compiler to support dynamic polymorphism. 
// Whenever a class contains a virtual function, the compiler creates a Vtable for that class. 
// Each object of the class is then provided with a hidden pointer to this table, known as Vptr.

// C++ program to show the working of vtable and vptr
#include <iostream>
using namespace std;

// base class
class Base {
public:
    virtual void function1()
    {
        cout << "Base function1()" << endl;
    }
    virtual void function2()
    {
        cout << "Base function2()" << endl;
    }
    virtual void function3()
    {
        cout << "Base function3()" << endl;
    }
};

// class derived from Base
class Derived1 : public Base {
public:
    // overriding function1()
    void function1()
    {
        cout << "Derived1 function1()" << endl;
    }
    // not overriding function2() and function3()
};

// class derived from Derived1
class Derived2 : public Derived1 {
public:
    // again overriding function2()
    void function2()
    {
        cout << "Derived2 function2()" << endl;
    }
    // not overriding function1() and function3()
};

// driver code
int main()
{
    // defining base class pointers
    Base* ptr1 = new Base();       // vptr -> Base_vtable
    Base* ptr2 = new Derived1();   // vptr -> Derived1_vtable
    Base* ptr3 = new Derived2();   // vptr -> Derived2_vtable
    
    // Base object calls its own functions (early binding, vptr -> Base_vtable)
    ptr1->function1(); // Calls Base::function1
    ptr1->function2(); // Calls Base::function2
    ptr1->function3(); // Calls Base::function3
    
    // Derived1 overrides function1(), but function2() & function3() remain from Base
    ptr2->function1(); // Calls Derived1::function1 (overridden)
    ptr2->function2(); // Calls Base::function2 (not overridden in Derived1)
    ptr2->function3(); // Calls Base::function3 (not overridden in Derived1)
    
    // Derived2 overrides function2(), inherits function1() from Derived1, and function3() from Base
    ptr3->function1(); // Calls Derived1::function1 (inherited)
    ptr3->function2(); // Calls Derived2::function2 (overridden in Derived2)
    ptr3->function3(); // Calls Base::function3 (inherited)

    // deleting objects
    delete ptr1;
    delete ptr2;
    delete ptr3;

    return 0;
}



// A VTable is a hidden table (array of function pointers) maintained by the compiler for each class with virtual functions.
// Each class with virtual functions has one VTable.


// Every object of a class with virtual functions contains a hidden pointer (vptr).
// The vptr points to the VTable of its corresponding class.


// When an object of Base is created, its vptr points to Base's VTable.
// When an object of Derived is created, its vptr points to Derived's VTable.
// When calling a virtual function via a base class pointer, the vptr ensures the correct function is called.


// If no virtual functions exist, no VTable and VPtr are created.

// VTable is created at compile time.
// VPtr is assigned at runtime when an object is instantiated.

// Vtable and Vptr exists for the pure virtual class also 



// Q1: Does every object of a derived class have a separate VTable?
// No, each class has one VTable, and all objects share it. Each object, however, has a separate VPtr.

// Q2: Can we override a non-virtual function?
// Yes, but it will lead to function hiding instead of overriding.

// Q3: Does a class without virtual functions have a VTable?
// No, only classes with virtual functions have VTables.

// Q4: What happens if a class has multiple virtual functions?
// All virtual functions are stored in the same VTable.