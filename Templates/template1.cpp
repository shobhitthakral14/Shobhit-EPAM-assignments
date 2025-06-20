#include<iostream>
using namespace std;

//The simple idea is to pass the data type as a parameter so that we don’t need to write the same code for different data types. 
//C++ adds two new keywords to support templates: ‘template’ and ‘typename’. 

//Templates are expanded at compiler time. This is like macros. 
//The difference is, that the compiler does type-checking before template expansion. 
//The idea is simple, source code contains only function/class, but compiled code may contain multiple copies of the same function/class. 


//FUNCTION TEMPELATE

// template <typename Tmax>Tmax mymax(Tmax x ,Tmax y)
// {
//     return (x>y)?x:y;
// }

// int main()
// {
//     cout<<mymax<int>(3,7)<<endl;
//     return 0;
// }


// If the function is also present 

template <typename T> void display(T a) {
    cout << "Template Function: " << a << endl;
}

// Overloaded function (not a template)
void display(int a) {
    cout << "Overloaded Function for int: " << a << endl;
}

int main() {
    display(10);        // Calls overloaded function (int version)
    display(3.14);      // Calls template function
    display("Hello");   // Calls template function
    return 0;
}