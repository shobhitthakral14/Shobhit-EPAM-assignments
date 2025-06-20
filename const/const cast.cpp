// The const_cast operator removes const qualification from a variable.

#include <iostream>
using namespace std;

void modifyValue(const int* ptr) {
    int* modifiablePtr = const_cast<int*>(ptr);
    *modifiablePtr = 50;  // Safe only if the original data was not truly `const`
}

int main() {
    int num = 30;
    modifyValue(&num);
    cout << "Modified num: " << num << endl;  // Output: 50
    return 0;
}
