// Pointers are symbolic representations of addresses.
//  They enable programs to simulate call-by-reference as well as to create and manipulate dynamic data structures.

// We all know that every function’s code resides in memory, so every function has an address like all other variables in the program. 

//The name of a function can be used to find the address of the function. 
//We can get the address of a function by just writing the function’s name without parentheses in the function.

//The function pointer is used to point functions, similarly, the pointers are used to point variables. 

// The function pointer is either used to call the function or it can be sent as an argument to another function.


// It can be used to invoke the function indirectly.
// Function pointers allow dynamic function calls, callbacks, and are used in scenarios like sorting, event handling, and polymorphism.

// Declaring
// return_type (*FuncPtr) (parameter type, ....); 

// Referencing
// FuncPtr= function_name;

// Dereferencing
// data_type x=*FuncPtr;



