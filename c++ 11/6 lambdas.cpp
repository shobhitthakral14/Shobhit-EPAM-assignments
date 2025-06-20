// A lambda expression is an anonymous function you can define inline. It’s mainly used to pass behavior (functionality) around — perfect for callbacks.

// syntax

//[ capture_list ] ( parameter_list ) -> return_type {
    // function body
// };


// [] — Capture variables from the outer scope.

// () — Parameters, like a normal function.

// -> return_type — Optional return type.

// {} — Function body.



// Syntax	Meaning
// []	Captures nothing
// [=]	Captures all automatic variables by value
// [&]	Captures all automatic variables by reference
// [x]	Captures x by value
// [&x]	Captures x by reference
// [=, &y]	Captures all by value except y by reference
// [&, x]	Captures all by reference except x by value




// When you capture a variable by value in a lambda, the lambda gets its own copy of that variable.

// By default, this copy is const inside the lambda, so you cannot modify it.

// If you try to modify a captured-by-value variable without mutable, the compiler will give an error.

// Using the mutable keyword on the lambda allows you to modify the copy of the captured variable inside the lambda.



// int x = 10;
// auto lambda = [x]() mutable {
//     x++;
//     std::cout << x << std::endl;  // OK
// };
// lambda();
// // x is still 10





// return type in lambdas 

// If the lambda body has a single return statement or implicitly returns an expression, the compiler deduces the return type automatically.
// You can specify the return type explicitly after the parameter list, using -> type.

//auto lam = [](int x, int y) -> double {
//     return x / static_cast<double>(y);  // force return type to double
// };



// GENERIC LAMBDAS 

// U CAN PASS AUTO IN PARAMTER LIST 


// auto print = [](auto x) {
//     std::cout << x << std::endl;
// };
// print(5);
// print("hello");



// STORING A LAMBDA IN STD::FUNCTION 

// std::function<int(int)> f = [](int x) { return x * x; };





// SIZE OF THE LAMBDAS

// Depends on captured variables.

// If no capture → usually zero or minimal size.           // 1 byte for unique address





// CAN LAMBDAS BE RECURSIVE 

// Not directly. Use std::function.

// std::function<int(int)> factorial = [&](int n) {
//     return (n <= 1) ? 1 : n * factorial(n - 1);
// };









// #include <iostream>
// #include<functional>
// int main() {
//     int y=10;
//    std::function<int(int)> f = [y](int x) mutable { 
//        y++;
//        return x*x*y; };
//    std::cout<<f(10);

//     return 0;
// }











// lambdas without capture               STD::FUNCTION()

#include <iostream>
#include <functional>

void doSomething(std::function<void()> callback) {
    std::cout << "Doing something...\n";
    callback(); // call the lambda
}

int main() {
    doSomething([]() {
        std::cout << "Lambda callback executed!\n";
    });
    return 0;
}
// here lambda is passed as a callback 




// LAMDAS WITH CAPTURE               STD::FUNCTION()

#include <iostream>
#include <functional>

void doSomething(std::function<void()> callback) {
    callback();
}

int main() {
    int x = 10;
    doSomething([x]() {
        std::cout << "Captured value: " << x << "\n";
    });
}


// [x] means capture x by value.

// [&x] would mean capture x by reference.




//// USING FUNCTION POINTER 

// You can use a lambda without capture as a function pointer:



void callFunc(void (*fp)()) {
    fp();
}

int main() {
    callFunc([]() {
        std::cout << "No capture lambda as function pointer\n";
    });
}





// if lambda doesn't has capture it can be converted to function pointer
// but if it has capture it can be stored only through std::function and auto 




// can also be used inside class in cpp20  by using this 
class MyClass {
    int x = 42;
public:
    void run() {
        auto f = [this]() { std::cout << x; };
        f();
    }
};







//Be careful when capturing references — if the original variable goes out of scope, using the lambda later can cause undefined behavior.










// PITFALLS OF LAMBDAS


//1.) In capturing by refernce there might be possibility that the captured variable might go out of scope before the execution of lambda
    //   this leads to undefined behaviour
    //   Solution: capture them by value ([=]), or by individual variable by value.

// 2.) Capturing by value ([=]) copies the variable, but if the variable is large or expensive to copy, it can lead to performance issues.
    // Solution: use references ([&]), or capture a specific variable by reference but others by value, use specific captures.

// 3.) lambda has a return type that isn't clearly inferred by the compiler, it can lead to confusing behavior, especially when the return type differs.
    // Solution: Specify the return type explicitly, makes the lambda's behavior more predictable and clear.


// 4.) cannot use recursive function directly in lambdas 
    // Solution: make it assign to std::funtion and call the function recursively 

// 5.) store a lambda in a std::function, especially if the lambda captures large objects or resources, it can lead to memory leaks or performance problems due to unnecessary allocations.
    //  Solution: If you don't need to store the lambda in a std::function, consider using a direct call instead of storing it in a generic function object. 
    //  Otherwise, use std::function only when necessary and be mindful of what gets captured.

// 6.) Using lambdas excessively for everything can make the code harder to read and understand.
    // Solution: Use lambdas for small, simple tasks, but for more complex operations, consider defining a regular function.

// 7.) unintentionally capture variables by reference in a lambda and modify them inside the lambda. This can lead to confusion and unexpected side effects.
    // Solution: If you want to modify a captured variable inside the lambda, be explicit and understand the effects. 
    // Use the mutable keyword if you want to modify captured variables that are captured by value.