#include <iostream>

int main() {
    int x = 10;

    auto lambda = [x]() mutable { x += 5; std::cout << x << std::endl; };
    lambda(); // Output: 15
    std::cout << x << std::endl; // Output: 10 (original x is unchanged)
    
    return 0;
}


// mutable allows modifying the captured copy (not the original).