// A functor (function object) is any object that can be called like a function.
// This is possible because the class overloads the function call operator operator().
// Functors provide a way to wrap functionality into objects, which can carry state or behave like functions.



#include <iostream>

class Adder {
    int x;
public:
    Adder(int val) : x(val) {}

    // Overload function call operator
    int operator()(int y) {
        return x + y;
    }
};

int main() {
    Adder addFive(5);
    std::cout << addFive(10);  // Output: 15
    return 0;
}


// Stateful: Unlike normal functions, functors can hold internal state via member variables.

// Inline & Efficient: They can be inlined by the compiler.

// More flexible: You can add constructors, destructors, member variables, and helper functions.

// Used extensively in STL: Standard algorithms take functors for custom operations (e.g., std::sort, std::for_each).

// | Aspect            | Functors             | Lambdas                   | Function Pointers         |
// | ----------------- | -------------------- | ------------------------- | ------------------------- |
// | Can hold state?   | Yes                  | Yes (since C++11)         | No                        |
// | Can be inlined?   | Yes                  | Yes                       | Depends on implementation |
// | Type              | Class type           | Unique compiler-generated | Pointer                   |
// | Syntax complexity | Verbose (need class) | Lightweight               | Simple                    |
// | Can be templated? | Yes                  | Limited                   | No                        |


 // can we use functor in multithreading 
// Yes, but you must ensure thread safety if the functor holds mutable state shared between thread





// STATEFUL
#include <iostream>

class Adder {
    int base;
public:
    Adder(int b) : base(b) {}

    int operator()(int x) const {
        return base + x;
    }
};

int main() {
    Adder add5(5);   // functor holds state: base = 5
    std::cout << add5(10) << "\n";  // outputs 15 (5 + 10)
    
    Adder add10(10); // functor holds state: base = 10
    std::cout << add10(10) << "\n"; // outputs 20 (10 + 10)

    return 0;
}

// Unlike a regular function or funct/ion pointer, a functor can have member variables.






// OVERLOAD OPERATOR WITH MULTIPLE SIGNATURE 

struct Overloaded {
    void operator()(int x) { std::cout << "int: " << x; }
    void operator()(double d) { std::cout << "double: " << d; }
};


// POLYMORPHIC 

struct Base {
    virtual void operator()(int) = 0;
    virtual ~Base() {}
};

struct Derived : Base {
    void operator()(int x) override {
        std::cout << "Derived: " << x;
    }
};




// TEMPLATED FUNCTOR 

template <typename T>
struct Square {
    T operator()(T x) const { return x * x; }
};




// MUTABLE IN FUNCTORS 

#include <iostream>

class Counter {
    mutable int count;  // mutable allows modification even in const method
public:
    Counter() : count(0) {}

    int operator()() const {  // operator() is const
        return ++count;       // still can modify count because it's mutable
    }
};

int main() {
    const Counter c;  // even if c is const, operator() can modify count
    std::cout << c() << "\n";  // 1
    std::cout << c() << "\n";  // 2
    std::cout << c() << "\n";  // 3
}




// Lambdas are syntactic sugar for functors (compiler generates a class under the hood).    
// Lambdas are essentially anonymous functors with a hidden class generated by the compiler.



//functors in thread 


// struct Task {
//     void operator()() {
//         std::cout << "Running in thread";
//     }
// };
// std::thread t(Task{});
