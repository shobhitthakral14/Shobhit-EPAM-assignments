#include <iostream>

// A normal function without parameters

// void greet() {
//     std::cout << "Hello, World!" << std::endl;
// }

// int main() {
//     void (*funcPtr)(); // Function pointer declaration
//     funcPtr = &greet;  // Assigning function address
//     funcPtr();         // Calling the function via pointer

//     return 0;
// }

//& is optional 


// FUNCTION POINTER WITH VARIABLE 

#include <iostream>

// Function with parameters
void add(int a, int b) {
    std::cout << "Sum: " << (a + b) << std::endl;
}

int main() {
    void (*funcPtr)(int, int); // Function pointer declaration
    funcPtr = add;             // Assign function address
    funcPtr(3, 7);             // Call function via pointer

    return 0;
}

// The function pointer funcPtr can store the address of add(), which takes two int parameters.