// // Functors can store state and change behavior dynamically.

// #include <iostream>
// // Functor that counts how many times it's called


// class Counter {
//     int count;

// public:
//     Counter() : count(0) {}

//     void operator()() {
//         count++;
//         std::cout << "Called " << count << " times.\n";
//     }
// };

// int main() {
//     Counter counter;
//     counter(); // Called 1 times.
//     counter(); // Called 2 times.
//     counter(); // Called 3 times.
//     return 0;
// }


// Useful in performance monitoring, tracking function calls, etc.




//You can create functors that take parameters and modify behavior.


#include <iostream>
#include <cmath>

class Power {
public:
    double operator()(double base, double exponent) const {
        return std::pow(base, exponent);
    }
};

int main() {
    Power power;
    std::cout << power(2, 3) << std::endl; // Output: 8
    return 0;
}
//The functor Power computes base^exponent.
// It works like a function but can be extended with additional features.