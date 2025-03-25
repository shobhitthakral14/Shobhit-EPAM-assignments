#include<iostream>
#include <functional>
// std::function from <functional> can store lambda functions dynamically.
using namespace std;

int main() {
    std::function<int(int, int)> multiply = [](int a, int b) { return a * b; };
    std::cout << multiply(3, 4) << std::endl; // Output: 12
    return 0;
}
