// A raw pointer is a variable that holds the memory address of another variable.

int a = 10;
int* ptr = &a; // ptr stores the address of a

// here ptr stores the address of a 



// int * means pointer to int 

// types 

// 1.) dangling 

// Points to deallocated memory.

// int* p = new int(5);
// delete p;
// *p = 10; // Undefined behavior


// 2.) nullptr

// int *p=nullptr;


// 3.) const pointer 

// Either the pointer is constant or the value it points to is constant

// const int* p;     // can't modify value
// int* const p2;    // can't change address
// const int* const p3; // both fixed


// 4.) wild pointer 
// A wild pointer is an uninitialized pointer that points to a garbage memory location
// int* p; // wild pointer
// *p = 10; // ❌ undefined behavior


// // MEMORY MANAGEMENT 

// int* p = new int(100);
// delete p; // Must delete to avoid memory leak



// // IN ARRAY 

// int* arr = new int[5];
// // ...
// delete[] arr;       // it ensures that destructor of all the elements are called 

// if you allocate memory for an array using new[], you cannot delete a single element of that array using delete. 
// You must use delete[] to free the entire block of memory allocated.

// use individual allocation 

//int* arr[5];
// for (int i = 0; i < 5; ++i)
//     arr[i] = new int(i * 10);  // separate allocations

// delete arr[2]; // ✅ Valid



// use vector pointer 
// std::vector<int*> vec(5);
// for (int i = 0; i < 5; ++i)
//     vec[i] = new int(i * 10);

// delete vec[2]; // ✅


// in normal raw pointer the allocation is manual through new and deallocation is also manual thorugh delete 

// so it is unsafe andd risky 



// double delete 

// int* ptr = new int(10);
// delete ptr;   // ✅ First delete is fine
// delete ptr;   // ❌ Undefined behavior! Double delete


// The first delete deallocates memory. The second delete accesses already freed memory, leading to undefined behavior.
// Always set pointers to nullptr after deletion to guard against this.

// int* ptr = new int(10);
// delete ptr;
// ptr = nullptr;  // Prevents accidental reuse or double delete

// delete ptr;     // Safe: deleting nullptr is a no-op in C++




// int* p1, p2   // here p1 is pointer to int and p2 is just int 




// a pointer can only have int as 0 other value may compile but can give runtime clashes 



// malloc doesnt't call constructor and destructor
// new is type safe and call constructor and destructor 



// POINTER ARITHMETIC 

// Pointer arithmetic allows you to perform operations like addition, subtraction, increment, and decrement on pointers
//. It's mostly used with arrays or dynamically allocated memory blocks.

// int arr[5] = {10, 20, 30, 40, 50};
// int* ptr = arr;
// std::cout << *(ptr + 2); // Output: 30
// ptr++;  // Now points to arr[1]


// int arr[] = {5, 10, 15, 20};
// int* p = arr;

// for (int i = 0; i < 4; i++) {
//     std::cout << *(p + i) << " ";  // Outputs: 5 10 15 20
// }




// VOID POINTER 


//A void* (void pointer) is a generic pointer that can hold the address of any data type, but cannot be dereferenced directly.
// void* ptr;
// int x = 10;
// ptr = &x;  // Valid: void* can point to any type


// //*ptr = 5; // ❌ Error: 'void*' is not a valid dereference
//std::cout << *(static_cast<int*>(ptr)); // ✅ Outputs: 10





// POINTER TO POINTER

#include <iostream>
using namespace std;
int main() {
 int a = 5;
int* p = &a;
int** pp = &p; // pointer to a pointer
    cout<<p<<endl;
    cout<<pp<<endl;
    return 0;
}






// nullptr → C++11 onwards, type-safe.

// NULL → macro for 0, not type-safe.

// 0 → could be int or null.





// #include <iostream>
// using namespace std;

// int main() {
//     int* p = new int;  // dynamically allocate memory
//     *p = 10;           // assign value
//     cout << *p << endl;  // output: 10
//     delete p;          // free memory
// }





//Pointers can be nullptr and reassigned. References must be bound at initialization and cannot be null.