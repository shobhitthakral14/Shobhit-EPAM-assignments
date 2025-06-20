// Casting is the process of explicitly converting one data type to another.

// ✅ Two types of casting in C++:
// 1. Implicit Casting (Done automatically by the compiler)
// 2. Explicit Casting (Done manually by the user using casting operators)

// ✅ C++ provides 4 types of explicit casts:
    // static_cast
    // dynamic_cast
    // const_cast
    // reinterpret_cast

//-----------------------------------------------------------

// ✅ static_cast:
// - Performed at compile-time.
// - No runtime checks.
// - Safe for converting related types (e.g., upcasting in inheritance, int → float).
// - Unsafe for downcasting without checks.



#include<iostream>

class Base {};

class Derived : public Base {};

int main() {
    Derived d;
    Base* b = static_cast<Base*>(&d);  // ✅ Safe upcast
}

//-----------------------------------------------------------

// ✅ dynamic_cast:
// - Performed at runtime.
// - Safe downcasting with runtime type check.
// - Requires at least one virtual function in base class (i.e., polymorphic base).

class Base {
public:
    virtual ~Base() {}  // ✅ Polymorphic base class
};

class Derived : public Base {};

int main() {
    Base* b = new Derived;
    Derived* d = dynamic_cast<Derived*>(b);  // ✅ Safe downcast
}

//-----------------------------------------------------------

// ✅ const_cast:
// - Used to remove or add `const` or `volatile` qualifiers.
// - Modifying a truly const object after casting results in **undefined behavior**.

void modify(int* ptr) {
    *ptr = 100;
}

int main() {
    const int x = 10;
    modify(const_cast<int*>(&x));  // ⚠️ Undefined behavior
}

//-----------------------------------------------------------

// ✅ reinterpret_cast:
// - Used for low-level bit reinterpretation.
// - Dangerous: no type safety or checks.
// - Used for casting unrelated pointer types or pointer ↔ integer conversions.

int main() {
    int a = 65;
    char* p = reinterpret_cast<char*>(&a);  // ✅ Interpret bits as char pointer
    std::cout << *p << std::endl;  // May print 'A'
}
