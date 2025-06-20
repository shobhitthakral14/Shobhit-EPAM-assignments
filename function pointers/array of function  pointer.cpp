#include <iostream>

void add(int a, int b) { std::cout << "Addition: " << (a + b) << std::endl; }
void subtract(int a, int b) { std::cout << "Subtraction: " << (a - b) << std::endl; }

int main() {
    void (*operations[2])(int, int) = {add, subtract}; // Array of function pointers

    operations[0](10, 5); // Calls add(10, 5)
    operations[1](10, 5); // Calls subtract(10, 5)

    return 0;
}

// Pointers to member functions allow calling object methods dynamically.    
// Function pointers are being replaced by lambdas in modern C++.