// std::weak_ptr is a smart pointer introduced in C++11 that provides a non-owning ("weak") reference to an object managed by std::shared_ptr.

// shared_ptr increases the reference count — weak_ptr does not.


#include <iostream>
#include <memory>

class B; // Forward declaration

class A {
public:
    std::shared_ptr<B> ptrB;
    A() { std::cout << "A Constructor\n"; }
    ~A() { std::cout << "A Destructor\n"; }
};

class B {
public:
    std::shared_ptr<A> ptrA;
    B() { std::cout << "B Constructor\n"; }
    ~B() { std::cout << "B Destructor\n"; }
};

int main() {
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();
    a->ptrB = b;
    b->ptrA = a;

    return 0; // Memory leak! Destructors won't be called
}



class B;

class A {
public:
    std::weak_ptr<B> ptrB;  // weak_ptr used to break circular reference
    A() { std::cout << "A Constructor\n"; }
    ~A() { std::cout << "A Destructor\n"; }
};

class B {
public:
    std::shared_ptr<A> ptrA;
    B() { std::cout << "B Constructor\n"; }
    ~B() { std::cout << "B Destructor\n"; }
};

int main() {
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();
    a->ptrB = b;  // weak_ptr prevents circular reference
    b->ptrA = a;

    return 0; // No memory leak, destructors are called
}


// It must be initialized from a shared_ptr.

// It doesn't affect the reference count.

//  You can check if the object still exists using .expired() or .lock().
// std::shared_ptr<int> sp = std::make_shared<int>(100);
// std::weak_ptr<int> wp = sp;

// if (!wp.expired()) {
//     std::shared_ptr<int> temp = wp.lock(); // creates shared_ptr temporarily
//     std::cout << *temp << "\n";
// }




// In observer patterns, where the observer doesn’t need to keep the subject alive.

// To break cycles in ownership graphs.

// For caching, where you don’t want to prolong object lifetime unless it's used.



// YOU MUST NOT DEREFERNCE A WEAK POINTER DIRECTLY FIRT LOCK IT OTHERWISE IT WILL GIVE COMPILE TIME ERROR 

// use_count gives u how many shared_ptr are owning the object 

// weak pointer only works with shared not unique 






// Use weak_ptr when:

// You want to observe a shared_ptr without affecting its lifetime.

// You need to prevent cyclic references.

// Always check .expired() or use .lock() before accessing the object.