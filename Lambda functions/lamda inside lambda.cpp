#include <iostream>

int main() {
    auto cal = [](int a, int b, int choice) {
        switch (choice) {
            case 1: return [=]() { return a + b; };  // Addition
            case 2: return [=]() { return a - b; };  // Subtraction
            case 3: return [=]() { return a * b; };  // Multiplication
            case 4: return [=]() { return (b != 0) ? a / b : 0; };  // Division
            default: return [=]() { return 0; };  // Default case
        }
    };

    // Example Usage
    auto addLambda = cal(5, 3, 1);  // Returns a lambda for addition
    auto subLambda = cal(10, 4, 2); // Returns a lambda for subtraction

    std::cout << "Addition (5+3): " << addLambda() << std::endl;
    std::cout << "Subtraction (10-4): " << subLambda() << std::endl;

    return 0;
}
