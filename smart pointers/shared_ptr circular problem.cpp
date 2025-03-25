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
