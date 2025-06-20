// In C++, callback functions are a powerful mechanism to achieve decoupling, flexibility, and inversion of control in code.
// A callback is simply a function passed as an argument to another function and is invoked (called back) at a suitable point in the higher-order function’s execution.

// It allows a caller to customize behavior of a function without modifying the function itself.

// It is often used in event handling, asynchronous operations, custom comparators, etc.

// 1/) USING FUNCTION POINTER 



// You define a function (callback).

// You pass its pointer to another function.

// The other function calls it at the appropriate time.


// #include <iostream>
// using namespace std;

// // A simple callback function
// void myCallback(int x) {
//     cout << "Callback called with value: " << x << endl;
// }

// // A function that accepts a function pointer as a callback
// void process(int value, void (*callback)(int)) {                           // here A function pointer (*callback)(int) — i.e., a pointer to a function that takes an int and returns void.
//     cout << "Processing value: " << value << endl;

//     // Call the callback function
//     callback(value);
// }

// int main() {
//     process(42, myCallback);  // Pass callback to function
//     return 0;
// }



// mycallback is invoked during the calling of process
//When process runs, it explicitly calls the callback.
// mycallback is a callback funcion and process is a high order function which takes mycallback as an argument x






// 2.) USING STD::FUNCTION


#include <iostream>
#include <functional> // for std::function

using namespace std;

// A function to be used as callback
void myCallback(int x) {
    cout << "Callback called with value: " << x << endl;
}

// Function that accepts a callback
void process(int value, std::function<void(int)> callback) {
    cout << "Processing value: " << value << endl;
    callback(value); // Call the callback
}

int main() {
    process(42, myCallback); // Pass a function

    // Using lambda as callback
    process(100, [](int x) {
        cout << "Lambda callback with value: " << x << endl;
    });

    return 0;
}




//| Aspect              | Function Pointer             | `std::function`                       |
// | ------------------- | ---------------------------- | ------------------------------------- |
// | Flexibility         | Only regular functions       | Any callable (function, lambda, etc.) |
// | Stateful            | ❌ No                         | ✅ Yes (e.g., lambdas with captures)   |
// | Type Safety         | Weaker (can be misused)      | Stronger type checking                |
// | Null Safety         | Must check manually          | Throws `std::bad_function_call`       |
// | Performance         | Very fast (no indirection)   | Slight overhead (type erasure)        |
// | Object-oriented use | ❌ Hard with member functions | ✅ Easy with `std::bind`, lambdas      |



// lambdas with capture can be used in std::function only not in function pointers 

// //How does C++ handle callback lifetime and object ownership?
// You must ensure the callback target outlives the callback itself.

// Use std::shared_ptr, weak_ptr, or capture carefully to avoid dangling pointers or memory leaks.







// REAL TIME USECASE OF CALL BACK 


// bool customCompare(int a, int b) {
//     return a > b;
// }

// std::sort(vec.begin(), vec.end(), customCompare);

// 1-> sorting with custom comparator 
// 2-> multithreading 
// 3.-> asynchronus programming 








// LAMBDAS AS CALLBACK 



// A capture is a way for a lambda to access variables that are not passed as parameters, but are defined in the same scope where the lambda is created.

// auto lambda = [](int x) {
//     cout << x << endl;
// };
// This lambda only uses its own parameter x.

// It doesn't access anything outside, so it doesn’t capture anything.


// capture 
// int a = 10;
// auto lambda = [a](int x) {
//     cout << x + a << endl;  // Uses 'a' from outer scope          // here a is captured by value , making a copy 
// };
// lambda(5);  // Output: 15


// [capture_list](parameters) -> return_type {
//     // body
// }
