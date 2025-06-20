#include <iostream>

class MyClass {
public:
    void display() {
        auto lambda = []() { std::cout << "Inside class method" << std::endl; };
        lambda();
    }
};

int main() {
    MyClass obj;
    obj.display(); // Output: Inside class method
    return 0;
}

