// A singleton pattern is a design pattern that ensures that only one instance of a class can exist in the entire program.
// This means that if you try to create another instance of the class, it will return the same instance that was created earlier.








// EAGER INITIALIZATION 

// 1. Eager Initialization (Thread-safe but static memory use)
class Singleton {
private:
    static Singleton instance;  // created at program startup
    Singleton() {}
public:
    static Singleton& getInstance() {
        return instance;
    }
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};
Singleton Singleton::instance;  // definition



// this is thread safe but static memory allocation 




//  2.) Lazy Initialization (Not thread-safe)

#include <iostream>

class Singleton {
public:
    // Static method to access the singleton instance
    static Singleton& getInstance()
    {
        // If the instance doesn't exist, create it
        if (!instance) {
            instance = new Singleton();
        }
        return *instance;
    }

    // Public method to perform some operation
    void someOperation()
    {
        std::cout
            << "Singleton is performing some operation."
            << std::endl;
    }

    // Delete the copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

private:
    // Private constructor to prevent external instantiation
    Singleton()
    {
        std::cout << "Singleton instance created."
                  << std::endl;
    }

    // Private destructor to prevent external deletion
    ~Singleton()
    {
        std::cout << "Singleton instance destroyed."
                  << std::endl;
    }

    // Private static instance variable
    static Singleton* instance;
};

// Initialize the static instance variable to nullptr
Singleton* Singleton::instance = nullptr;

int main()
{
    // Access the Singleton instance
    Singleton& singleton = Singleton::getInstance();

    // Use the Singleton instance
    singleton.someOperation();

    // Attempting to create another instance will not work
    // Singleton anotherInstance; // This line would not
    // compile

    return 0;
}



// THREAD SAFE SINGLETON

#include<iostream>
using namespace std;


class singleton 
{
    public:
    
    static singleton& getinstance()
    {
        static singleton instance;
        return instance ;
    }
    
    void someoperations()
    {
        cout<<"singleton performing operations"<<endl;
    }
    
    singleton(const singleton &)=delete;
    singleton& operator =( const singleton &)=delete;
    
    private:
    
    singleton()
    {
        cout<<"singleton instance created"<<endl;
    }
    
    ~singleton()
    {
        cout<<"singleton instance destroyed "<<endl;
    }
};



int main()
{
    singleton & s=singleton::getinstance();
    s.someoperations();
}


// DOUBLE CHECK 

// class Singleton {
// private:
//     static Singleton* instance;
//     static std::mutex mtx;
//     Singleton() {}
// public:
//     static Singleton* getInstance() {
//         if (!instance) {
//             std::lock_guard<std::mutex> lock(mtx);
//             if (!instance)
//                 instance = new Singleton();
//         }
//         return instance;
//     }
//     Singleton(const Singleton&) = delete;
//     Singleton& operator=(const Singleton&) = delete;
// };
// Singleton* Singleton::instance = nullptr;
// std::mutex Singleton::mtx;





