// C++ idioms are common, efficient, and expressive coding patterns that make use of specific C++ features 
// (like RAII, templates, operator overloading, etc.) to solve problems elegantly. 


// RAII (Resource Acquisition Is Initialization)


// RAII is a C++ idiom that binds the lifecycle of resources (like memory, file handles, mutexes, sockets, etc.) to the lifetime of objects.
// When an object is created, it acquires a resource, and when it goes out of scope, its destructor automatically releases that resource.


// | Concept            | Description                                                                |
// | ------------------ | -------------------------------------------------------------------------- |
// | **Resource**       | Anything external: heap memory, file descriptor, lock, DB connection, etc. |
// | **Acquisition**    | Resource is acquired in the constructor.                                   |
// | **Initialization** | The resource is tied to object initialization.                             |
// | **Release**        | Destructor releases the resource automatically.                            |

// IT IS IMP BECAUSE 
// No leaks 
// cleaner code dont have to manually delete the resource
//exception safety - releases the resource even if exception is there 



// RAII in file handling 


#include<iostream>
#include<fstream>
using namespace std;

class FileHandler {
    ifstream file;
public:
    FileHandler(const string& filename) {
        file.open(filename);
    }
    ~FileHandler() {
        file.close(); // RAII handles cleanup
    }
};



// RAII in multithreading 

#include <mutex>
#include <iostream>

std::mutex mtx;

void criticalSection() {
    std::lock_guard<std::mutex> lock(mtx);  // RAII for locking
    std::cout << "Thread-safe operation" << std::endl;
    // mtx will be automatically unlocked when 'lock' goes out of scope
}



// Most STL containers like std::vector, std::unique_ptr, std::lock_guard implement RAII under the hood.

// In smart pointers they delete the object when it goes out of scope 





//----------------------------------------------PIMPL---------------------------------------------------------------------------------------------


// Pimpl (Pointer to Implementation) is a powerful C++ design idiom that hides implementation details from the public interface of a class, 
// improving encapsulation, compile-time efficiency, and binary compatibility.


//Instead of exposing all private members directly in the header file, you forward-declare a private Impl class and hold a pointer to it:


// WITHOUT PIMPL

// MyClass.h
// class MyClass {
// public:
//     void doSomething();
// private:
//     int data;
// };
// Here, every change in MyClass's private data (e.g., changing int data to float data) 
//forces recompilation of all files that include MyClass.h.





// WITH PIMPL

// MyClass.h

// class MyClass {
// public:
//     MyClass();
//     ~MyClass();
//     void doSomething();

// private:
//     class Impl;          // Forward declaration
//     Impl* pImpl;         // Pointer to implementation
// };


// MyClass.cpp

// #include "MyClass.h"
// #include <iostream>

// class MyClass::Impl {
// public:
//     void doSomething() {
//         std::cout << "Doing something!" << std::endl;
//     }
// };

// MyClass::MyClass() : pImpl(new Impl) {}
// MyClass::~MyClass() { delete pImpl; }

// void MyClass::doSomething() {
//     pImpl->doSomething();
// }



// ⚠️ Downsides of Pimpl

// Slight runtime overhead due to pointer dereferencing
// Increased complexity (especially with deep copies, move semantics)
// Potential for memory leaks or resource mismanagement if not handled properly



//It reduces compilation time (by minimizing header changes), but may add slight runtime overhead due to indirection.