#include<iostream>
using namespace std;

//An inline function in C++ is a function for which the compiler replaces the function call with the actual function definition during compilation.

// the compiler replaces each function call with the actual code of the function, avoiding the overhead of calling a function
//(pushing/popping stack, jumping to another memory location, etc.).


inline int square(int x)
{
    return x*x;
}


int main()
{
    cout<<"square of 5 is : "<<square(5)<<endl;
    return 0;
}

// Advantages

// faster exection
// reduce function call overhead
// better optimization
// useful for small functions 


// disadvantages 


// Increased Code Size (Code Bloat):
// Since the function code is copied at every call location, it increases the binary size of the program.
// This can lead to higher memory consumption, especially if the function is large and used frequently.


// Compiler's Decision:
// Even if you declare a function as inline, the compiler may ignore it if the function is too complex.



// For large functions (as it increases code size).
// If the function contains loops, recursion, or static variables.
// When using virtual functions (since they require runtime binding).
// In multi-file programs where inline functions may cause issues with linking.


