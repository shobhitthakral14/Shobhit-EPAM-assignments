#include <iostream>

class MyClass {
    // int value = 42;
public:
int value = 42;
    void display() {
        auto lambda = [this]() { std::cout << "Value: " << value << std::endl; };
        lambda();
    }
};

int main() {
    MyClass obj;
    obj.display(); // Output: Value: 42
    return 0;
}
