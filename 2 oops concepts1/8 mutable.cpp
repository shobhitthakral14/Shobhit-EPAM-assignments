// In C++, the mutable keyword is used to allow a member variable of a class or struct to be modified 
//even if it is part of an object that is declared const.

//By default, when an object is declared const, none of its member variables can be modified. 
//But sometimes you want specific data members to remain modifiable (e.g., for caching, logging, debugging). That’s where mutable comes in.


#include<iostream>
class Demo {
public:
    mutable int counter;

    void increment() const {        // const member function can only modify mutable data members if it is not mutable then it will compx error
        ++counter;  // allowed due to 'mutable'
    }
};

int main()
{
     Demo d;
    d.increment();  
    std::cout<<d.counter<<std::endl;
}

// | Point                                                 | Explanation                            |
// | ----------------------------------------------------- | -------------------------------------- |
// | `mutable` works only with **non-static** data members | Static members can't be marked mutable |
// | `mutable` can be used with `const` objects            | Enables exceptions to `const` rule     |
// | `mutable` doesn't affect thread-safety                | You must manage that yourself          |

// | Feature                 | `mutable` keyword                |
// | ----------------------- | -------------------------------- |
// | Works with              | Non-static data members only     |
// | Modifiable in `const`?  | ✅ Yes                           |
// | Used for                | Caching, logging, lazy-eval      |
// | Replaces need for       | Risky `const_cast` in many cases |
// | Thread-safe?            | ❌ No (must be managed manually) |
// | Transitive modification | ❌ No                             |




// void fun() const {

// }

// The function cannot modify any non-mutable member variables.

// The function can only call other const member functions.