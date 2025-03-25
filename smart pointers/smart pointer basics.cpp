// GFG 

// If anything is created inside heap pointers are used 
// if we want to change the original place of the resource we need pointer to change the original resource 

// java c# has garbage collector to deallocate memory that can be used again and again 

// smart pointer is a wrapper class over a pointer with * and -> overloaded 
// the idea of taking the class is that the destructor is automatically called when an object goes out of the scope 


#include <iostream>
#include <memory>
using namespace std;

class SmartPtr {
private:
    int* intptr;

public:
    // Constructor
    explicit SmartPtr(int* ptr) : intptr(ptr) {
        cout << "In Constructor" << endl;
    }

    // Destructor (deallocates memory)
    ~SmartPtr() {
        cout << "In Destructor" << endl;
        delete intptr;
    }


    // Overloaded * operator
    int& operator*() {
        cout << "In operator *  ";
        return *intptr;
    }

    // Overloaded -> operator
    int* operator->() {
        cout << "In operator ->" << endl;
        return intptr;
    }
};

// Sample class
class Sample {
public:
    void fun() {
        cout << "In Sample fun" << endl;
    }
};


// Main function
int main() {
    int* Myint = new int(15);
    cout << "MyInt val is: " << *Myint << endl;
    delete Myint; // Prevent memory leak

    // Using SmartPtr
    SmartPtr ptr(new int(10));
    cout << "Value is: " << *ptr << endl;

    // Using Smart Pointer with Sample Class
    Sample* sam;
    sam->fun();

    return 0;
}




// for all the pointers means using templates


// template <class T> class SmartPtr {
//     T* ptr; 
// public:
    
//     explicit SmartPtr(T* p = NULL) { ptr = p; }

    
//     ~SmartPtr() { delete (ptr); }

//     T& operator*() { return *ptr; }
//     T* operator->() { return ptr; }
// };