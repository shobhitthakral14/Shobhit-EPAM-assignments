#include <iostream>

class Math {
    public:
    int (*operation)(int, int); // Function pointer as a class member
};

int multiply(int a, int b) { return a * b; }

int main() {
    Math math;
    math.operation = multiply; // Assign function pointer

    std::cout << "Product: " << math.operation(3, 4) << std::endl; // Output: 12
    return 0;
}
