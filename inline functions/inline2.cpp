#include <iostream>
using namespace std;

// Inline function for addition
inline int add(int a, int b) {
    return a + b;
}

// Inline function for subtraction
inline int subtract(int a, int b) {
    return a - b;
}

// Inline function for multiplication
inline int multiply(int a, int b) {
    return a * b;
}

// Inline function for division
inline double divide(int a, int b) {
    if (b == 0) {
        cout << "Error! Division by zero is not allowed." << endl;
        return 0;
    }

    //  return static_cast<double>(a)/b

    return (double) (a)/b;
}

int main() {
    int num1 = 10, num2 = 5;
    int num3 = 7, num4 = 2;

    cout << "Addition: " << add(num1, num2) << endl;
    cout << "Subtraction: " << subtract(num1, num2) << endl;
    cout << "Multiplication: " << multiply(num1, num2) << endl;
    cout << "Division: " << divide(num1, num2) << endl;

    // Demonstrating integer vs floating-point division
    // this will give you interger 
    cout << "Integer Division (7 / 2): " << num3 / num4 << endl;
    // this will give you float 
    cout << "Floating-Point Division (7 / 2): " << divide(num3, num4) << endl;

    return 0;
}
