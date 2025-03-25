#include<iostream>
using namespace std;

// C++ 11 introduced lambda expressions to allow inline functions which can be used for short snippets of code that are not going to be reused.
// Therefore, they do not require a name. They are mostly used in STL algorithms as callback functions.

//They were introduced in C++11 and have been improved in C++14 and C++17.



// [capture](parameters) -> return_type { function_body };


//Generally, the return-type in lambda expressions is evaluated by the compiler itself and we don’t need to specify it explicitly. 
//However, in some complex cases e.g. conditional statements, the compiler can’t determine the return type and explicit specification is required.


// A lambda expression can have more power than an ordinary function by having access to variables from the enclosing scope.
// We can capture external variables from the enclosing scope in three ways using capture clause:

// [&]: capture all external variables by reference.
// [=]: capture all external variables by value.
// [a, &b]: capture ‘a’ by value and ‘b’ by reference.

#include <iostream>

int main() {
    //auto is used because lambdas have unique, compiler-generated types.
    auto greet = []() { std::cout << "Hello from Lambda!" << std::endl; };
    greet(); // Calling the lambda function
    return 0;
}

