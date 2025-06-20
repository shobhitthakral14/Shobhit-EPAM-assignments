// #include <iostream>
// using namespace std;

// PASS BY VALUE

// void modifyValue(const int num) {
//     // num = 20;  // ❌ Error: Cannot modify a const parameter
//     cout << "Inside function: " << num << endl;
// }

// int main() {
//     int x = 10;
//     modifyValue(x);
//     cout << "Outside function: " << x << endl;  
//     return 0;
// }

// The const prevents modification inside modifyValue().
// The original variable x remains unchanged since it's passed by value.

#include <iostream>
#include <string>
using namespace std;


void modifyString(const string str) {
    // str += " World";  // ❌ Error: Cannot modify a const parameter
    cout << "Inside function: " << str << endl;
}

int main() {
    string text = "Hello";
    modifyString(text);
    cout << "Outside function: " << text << endl;  // text is still "Hello"
    return 0;
}


// The const prevents modification inside the function.
// Since str is passed by value, a copy is created, and changes (if allowed) wouldn't affect the original.




//key points

// Pass by Value creates a copy of the argument, so modifications inside the function do not affect the original.

