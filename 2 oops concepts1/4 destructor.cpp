// A destructor is a special member function of a class that is executed automatically when an object goes out of scope or is explicitly deleted. \
// Its primary purpose is to release resources like memory, file handles, sockets, etc., that were acquired during the object's lifetime.


// 🧠 Key Properties of Destructors

// | Property                 | Description                                                               |
// | ------------------------ | ------------------------------------------------------------------------- |
// | **Name**                 | Same as the class name, but preceded by `~` (tilde).                      |
// | **No Arguments**         | A destructor **cannot** take arguments.                                   |
// | **No Return Type**       | Destructors don't return anything, not even `void`.                       |
// | **One per class**        | A class can have **only one destructor**.                                 |
// | **Automatically called** | When an object goes out of scope or is deleted.                           |
// | **Cannot be overloaded** | Since it takes no arguments, it can't be overloaded.                      |
// | **Can be virtual**       | In case of polymorphism, to ensure proper destruction of derived objects. |
 

// #include<iostream>

// class name
// {
//     public:
//     name()
//     {
//         std::cout<<"constructor"<<std::endl;
//     }
//     ~name()
//     {
//         std::cout<<"destructor"<<std::endl;
//     }
// };


// 🧨 When is a Destructor Called?
// Local object – when it goes out of scope.

// Dynamically allocated object – when delete is used.

// Array of objects – delete[] is required.

// End of main() – for global/static objects.


// DESTRUCTOR IN INHERITANCE 


// If a base class pointer points to a derived class object, and the destructor is not virtual, 
// the derived class’s destructor won’t be called, causing memory/resource leaks.


#include<iostream>

class base
{
    public:
    base()
    {
        std::cout<<" base constructor"<<std::endl;
    }
    virtual ~base()
    {
        std::cout<<" base destructor"<<std::endl;
    }
};

class derived: public base
{
    public:
    derived()
    {
        std::cout<<" derived constructor"<<std::endl;
    }
    ~derived()
    {
        std::cout<<" derived destructor"<<std::endl;
    }
};

int main()
{
    base *obj=new derived();
    delete obj;
    return 0;
}

//🧠 ALWAYS make destructors virtual if your class is meant to be inherited.

// Destruction is reverse of order of construction means the derived will be called first then base will be called 


//⚠️ Common Mistakes

// | Mistake                                          | Consequence                                |
// | ------------------------------------------------ | ------------------------------------------ |
// | Not using `virtual` destructor in base class     | Only base destructor runs => leaks         |
// | Not using `delete[]` for arrays                  | Only first element's destructor called     |
// | Forgetting to free memory in destructor          | Memory leak                                |
// | Calling destructor manually (`obj.~ClassName()`) | Undefined behavior unless in placement new |



// can we overload destructor?
// No. Destructor cannot be overloaded because it cannot have parameters and has fixed name.


//if there is an exception in the constructor will the destructor be called?
//only for the fully constructed objects . For the obj who are not fully constructed there destructor will not be called 


// delete means deleting single obj delete[] means deleting array of obj 
// it may leads to undefined behaviour if we use delete instead of delete[]


// PURE VIRTUAL DESTRUCTOR 


class Abstract {
public:
    virtual ~Abstract() = 0;  // Pure virtual destructor
};

Abstract::~Abstract() {
    std::cout << "Pure virtual destructor called\n";
}



// We can throw exception in destructor as well by it is not recommended  
//Throwing from a destructor during stack unwinding causes terminate() to be called. Use noexcept specifier (~Class() noexcept).



// rule of 3 
// if we define a destructor we usually describe copy constructor and copy assingment operator 

class MyClass {
    MyClass(const MyClass&);            // Copy constructor
    MyClass& operator=(const MyClass&); // Copy assignment
    ~MyClass();                         // Destructor
};


// IN SMART POINTERS DESTRUCTOR IS CALLED AUTOMATICALLY 


// Manual destructor calls are rarely needed unless you're doing low-level memory management (placement new, custom allocators, etc.).
// In normal usage, let the compiler call destructors automatically.

