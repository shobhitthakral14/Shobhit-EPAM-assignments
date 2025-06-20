#include <iostream>
using namespace std;


// lambda function with parameters

// int main() {
//     auto add = [] (int a, int b) { return a + b; };
//     cout << "Sum: " << add(5, 3) << std::endl;
//     return 0;
// }


// lambda function with return type 

int main() {
    auto divide = [] (int a, int b) -> double { return static_cast<double> (a)/ b; };
    cout << "Result: " << divide(10, 3) << endl;
    return 0;
}


