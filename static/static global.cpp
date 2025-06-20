#include <iostream>
using namespace std;

// Global static variable
static int counter = 0;

void increment() {
    counter++;
    cout << counter << endl;
}

int main() {
    increment();
    increment();
    return 0;
}


// Unlike regular global variables, a global static variable has internal linkage, meaning it is accessible only within the file where it is defined.   
// Exists till the program ends
// Hides data from other files