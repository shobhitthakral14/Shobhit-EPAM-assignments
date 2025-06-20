// // WITHOUT CONST 

// // When you pass a pointer to a function, you are passing the memory address of a variable. Any changes made via the pointer affect the original variable.


// #include <iostream>
// using namespace std;

// void modifyValue(int *num) {  // Pointer parameter
//     *num = 20; // Dereferencing pointer modifies original value
// }

// int main() {
//     int x = 10;
//     cout<<"before passing it to function "<< x <<endl;
//     modifyValue(&x);  // Pass address of x
//     cout << "After function call: " << x << endl;  // Output: 20
//     return 0;
// }



// // WITH CONST


// #include <iostream>
// using namespace std;


// void displayValue(const int *num) {  // Pointer to constant integer
//     // *num = 20; ❌ Error: Cannot modify a const value
//     cout << "Value: " << *num << endl;
// }

// int main() {
//     int x = 10;
//     displayValue(&x);
//     cout << "After function call: " << x << endl;  // Output: 10 (Unchanged)
//     return 0;
// }




// PASSING NULLPTR TO THE FUNCTION 

//Since pointers can be NULL (nullptr in C++11+), you can check if an argument was passed.


// #include <iostream>
// using namespace std;
// void safeModify(int *num) {
//     if (num) {  // Check for NULL
//         *num = 20;
//     }
// }

// int main() {
//     int x = 10;
//     safeModify(&x);
//     cout << "After function call: " << x << endl;  // Output: 20

//     safeModify(nullptr);  // No crash since we checked for NULL
//     return 0;
// }




// PASSING FOR DYNAMICALLY CREATED MEMORY

// Pointers allow modifying dynamically allocated data.

// #include <iostream>
// using namespace std;

// void allocateMemory(int *ptr) {
//     *ptr = 100; // Modifies allocated memory
// }

// int main() {
//     int *num = new int(50);  // Dynamically allocate memory
//     cout << "Value Before: " << *num << endl;
//     allocateMemory(num);
//     cout << "Value: " << *num << endl;  // Output: 100
//     delete num;  // Free allocated memory
//     return 0;
// }





//Double Pointers (**) – Changing the Pointer Itself

#include <iostream>

void allocateNewMemory(int **ptr) {
    *ptr = new int(50);  // Change pointer to new memory
}

int main() {
    int *num = nullptr;
    allocateNewMemory(&num);
    std::cout << "Value: " << *num << std::endl;  // Output: 50
    delete num;
    return 0;
}
