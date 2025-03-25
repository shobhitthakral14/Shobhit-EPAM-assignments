#include <iostream>
#include <functional>

int main() {
    std::function<int(int)> factorial = [&](int n) {
        return (n <= 1) ? 1 : n * factorial(n - 1);
    };

    std::cout << factorial(5) << std::endl; // Output: 120
    return 0;
}
