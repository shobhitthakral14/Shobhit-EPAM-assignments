//The explicit keyword in C++ is used to prevent implicit type conversions for constructors and conversion operators.          
//It ensures that objects of a class are not implicitly created through unintended conversions, leading to safer and more predictable code.

#include <iostream>
using namespace std;

class Demo 
{
public:
    explicit Demo(int x) 
    { // Now conversion will not happen automatically
        std::cout << "Constructor called with value: " << x << std::endl;
    }
};

void func(Demo d) { } // Function expecting a Demo object

int main() {
    // func(10); // ERROR: Implicit conversion is not allowed

    func(Demo(10)); // This works, explicit conversion
    return 0;
}
