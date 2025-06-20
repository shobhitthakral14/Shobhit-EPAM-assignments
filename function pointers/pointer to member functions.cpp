#include <iostream>

class Calculator {
public:
    int add(int a, int b) { return a + b; }
};

int main() {
    Calculator calc;
    int (Calculator::*funcPtr)(int, int) = &Calculator::add; // Member function pointer

    std::cout << "Sum: " << (calc.*funcPtr)(5, 7) << std::endl; // Output: 12
    return 0;
}