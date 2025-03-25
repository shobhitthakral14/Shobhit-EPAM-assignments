// #include <iostream>
// using namespace std;

// PASS BY REFERENCE WITHOUT THE CONST


// void modifyValue(int &num) {  // Pass by reference
//     cout<<"before function call : "<<num<< endl;
//     num = 20; // Modifies the original variable
// }

// int main() {
//     int x = 10;
//     modifyValue(x);  // x is passed by reference
//     cout << "After function call: " << x << endl;  // Output: 20
//     return 0;
// }





#include <iostream>
using namespace std;

// PASSING BY REFERENCE 

void displayValue(const int &num) {  // Pass by const reference
    // num = 20;  ❌ Error: Cannot modify a const reference
    cout << "Value: " << num << endl;
}

int main() {
    int x = 10;
    displayValue(x);  // No copy is made
    cout << "After function call: " << x << endl;  // Output: 10 (unchanged)
    return 0;
}


// The function cannot modify the parameter.
// No copy is made, so it's efficient for large objects.



#include <iostream>
#include <string>
using namespace std;


void printString(const string &str) {  // Pass by const reference
    cout << "String: " << str << endl;
}

int main() {
    string text = "Hello, World!";
    printString(text);  // No copy is made
    return 0;
}

// If we used string str, the function would create a copy.
// Using const string &str prevents modification and avoids unnecessary copying.
// Use const & (const string &str) for large objects to avoid unnecessary copying while keeping them read-only.