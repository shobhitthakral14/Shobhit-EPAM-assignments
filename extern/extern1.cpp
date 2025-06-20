
// The extern keyword is used for linkage ans scope control . 
// It allows variables and functions to be shared across multiple files, making it crucial for modular programming.
 

// using extern with variables 


// create a file1.cpp
// in which define a variable globalvar and a function show () .           // EXTERN CANNOT BE USED WITH LOCAL VARIABLES

//// IF WE MAKE A VARIABLE EXTERN IN THE MAIN and that is not created in another file it will give error  

// #include <iostream>
// using namespace std;
// int globalVar = 100;  // Global variable definition

// void show() {
//     cout << "GlobalVar = " << globalVar << std::endl;
// }



// now to use this global variable in the main file we have to use extern keyword 
// here we first use extern int globalvar  and voi


// #include <iostream>
// extern int globalVar; // Declaration (not definition)
// void show(); // Function prototype

// int main() {
//     // show();
//     std::cout << "Accessing globalVar in file2.cpp: " << globalVar << std::endl;
//     return 0;
// }




// USES
// When you need to share global variables between multiple files.
// ✅ When you need to declare functions in headers for modular programming.
// ✅ When calling C functions inside C++ using extern "C".