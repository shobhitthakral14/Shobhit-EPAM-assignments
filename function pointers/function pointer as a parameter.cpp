#include <iostream>

// Function to print a greeting
void greetUser() {
    std::cout << "Hello, user!" << std::endl;
}

// Function that asks a user to continue and executes a callback
void askUser(void (*callback)()) {
    char response;
    std::cout << "Do you want to proceed? (y/n): ";
    std::cin >> response;

    if (response == 'y' || response == 'Y') {
        callback(); // Call the function passed as an argument
    } else {
        std::cout << "Process terminated." << std::endl;
    }
}

int main() {
    askUser(greetUser); // Pass function pointer
    return 0;
}


// #include <iostream>

// // A function that adds two numbers
// void add(int a, int b) {
//     std::cout << "Sum: " << (a + b) << std::endl;
// }

// // Function that takes a function pointer as an argument
// void executeOperation(void (*operation)(int, int), int x, int y) {
//     operation(x, y); // Call the function passed as an argument
// }

// int main() {
//     executeOperation(add, 5, 10); // Pass function pointer and arguments
//     return 0;
// }
