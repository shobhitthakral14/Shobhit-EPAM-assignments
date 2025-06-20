// A class is a user-defined blueprint for creating objects.
// It encapsulates data members and member functions into one unit.


// ------------------------------------OBJECT------------------------------------------

// An object is a real-world entity represented in code using classes. A class is like a blueprint, and an object is an actual instance created from that blueprint.


    // Memory for data members is allocated only when an object is created.
    // Member functions are shared among objects (only one copy). as the functions belongs to the class not the object and object use that code with its own data
    // Memory for the static data members are also shared and created only once , outside the object

// types of object 

// 1.)stack 
//      car car1;   // created and deleted automatically

// 2.) heap 

// car* car2=new car();
// delete car2; // need manual creation and deletion 

// 3.) const 

//     const car car3;    
// const object can only call const member functions 

// 4.) array of objects 

//     car cars[3];

// 5.) Dynamic array of objects

    // car* cars=new car[3];
    // delete[] cars;

// size of an object is 1 byte to ensure different address

// only data members get seperate copies member function are shared

// we cannot create object of the same class inside the class but pointer to the same class can be done   
// class A{
//     A a;   // not allowed 
//     A* b;  // allowed 

// }

// If we copy an object Copy constructor is called. If not defined, compiler provides a shallow copy version.

// destructor is called automatically when object goes out of scope(stack) OR delete is called (heap)

// when a derived object is assigned to base object only base part is copied . The derived part are sliced off this is called object slicing 

// anonymous object (unnamed objects) They are typically used when an object is needed only once and does not require reuse.
// typically used for constructor calls or temporary object 


// to prevent object copying ->delete copy constructor and assignment operator 

// if we pass an object in the function by value , the copy constructor is called and the copy of the object is passed
// so that if there is a change made inside the function it will happen to the copy not the original object

// if we pass by reference no copy constructor is called 
// if change made in the function it will change the original object

// when an object is returned by value 
// three possibilities can be there 
// 1.) copy constructor is called 
// 2.) move constructor is called 
// 3.) RVO (return value optimization) means  directly constructing it in the caller's space. NO COPY NO MOVE 


// same for const objects but const objects can Only call const functions 




    // --------------------ACCESS SPECIFIERS----------------------------------

// class can have 3 types of access specifiers
// access specifiers control and visibility and accessibility of class members   

    // private members are accessible inside the class only and by friend function and class (default)
    // public members are accessible from outside class 
    // protected members are accessible in derived classes and friend functions and classes 


// 1.)                      PRIVATE

// #include <bits/stdc++.h>
// using namespace std;

// class MyClass {
// private:
//     int x;

// public:
//     // Constructor initializes private member x
//     MyClass(int val) {
//         x = val;
//     }

//     // Member function accessing private member
//     void show() {
//         cout << x;
//     }

//     // Setter function to update private member
//     void setter(int set) {
//         x = set;
//     }

//     // Getter function to access private member
//     int getter() {
//         return x;
//     }
// };

// int main() {
//     MyClass obj(10);
//     obj.show();          // Prints 10
//     cout << endl;

//     obj.setter(15);      // Update x to 15
//     cout << obj.getter(); // Prints 15

//     // Direct access to obj.x would be an error:
//     // cout << obj.x;  // ❌ ERROR: 'x' is private
// }

// YOU CAN ACCESS AND INTITALIZE DATA MEMBERES INSIDE THE CLASS USING CONSTRUCTOR AND CAN USE IT IN MEMBER FUNCTIONS BUT CANNOT USE IT OUTSIDE THE CLASS DIRECTLY 
// FOR THAT U NEED TO MAKE GETTER SETTER FUNTIONS 
// THEY CANNOT BE ACCESSED JUST USING . OPERATOR LIKE IN PUBLIC  

// WE CAN ALSO ACCESS PRIVATE MEMBERS USING POINTER MANIPULATION / CASTING BUT THIS IS VERY UNSAFE AND NOT RECOMMENDED 

// #include <iostream>
// using namespace std;

// class A {
// private:
//     int x = 42;
// };

// int main() {
//     A obj;
//     int* ptr = (int*)&obj;  // cast object to int pointer
//     cout << "Accessed private member: " << *ptr << endl;
//     return 0;
// }

// it will break if the class has virtual functions 
// or compiler reorders members




// 2.) PROTECTED 

    // accessible within the class , friend function and friend class and derived classes 
    // not accessible outside the class directly 

//     class Base {
// protected:
//     int id;
// };

// class Derived : public Base {
// public:
//     void setId(int x) {
//         id = x; // allowed
//     }
// };

// YOU CAN ACCESS AND INITIALIZE PROTECTED DATA MEMBERS INSIDE THE CLASS USING THE CONSTRUCTOR 
// AND CAN USE THEM IN MEMBER FUNCTIONS,
// ALSO, PROTECTED MEMBERS CAN BE ACCESSED DIRECTLY IN DERIVED (SUB) CLASSES,
// BUT THEY CANNOT BE ACCESSED DIRECTLY OUTSIDE THE CLASS OR ITS DERIVED CLASSES USING THE . OPERATOR LIKE PUBLIC MEMBERS.
// TO ACCESS OR MODIFY THEM FROM OUTSIDE, YOU NEED TO PROVIDE GETTER AND SETTER FUNCTIONS.


// PUBLIC 

// we can access public members without creating object only if they are static 
// we can access all the members using . operator 



