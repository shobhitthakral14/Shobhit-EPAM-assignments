#include<iostream>
using namespace std;

// Pointer to Constant Data

// const int *ptr;   // it can be uninitalized 
// or initialised with the location of the already available 
// and the value can be changed

int main()
{
    const int a = 10;
    const int b = 20;
    const int *ptr = &a;  // pointer to a constant integer 

    cout<<*ptr<<endl;

    //*ptr = 15;  // ❌ Error: Cannot modify value through ptr
    ptr = &b;   // ✅ Allowed: Can change pointer itself
    cout<<*ptr<<endl;

    return 0;
}


//The data pointed to by ptr is constant (cannot be modified through ptr).
//The pointer itself (ptr) can be changed to point to another address.





// explain in short
// int a = 10, b = 20;

// // 1. Pointer to a constant value
// const int* p1 = &a;
// // *p1 = 20;  // ❌ Error: Cannot modify value
// p1 = &b;      // ✅ Allowed: Pointer can point to another address

// // 2. Constant pointer to a variable
// int* const p2 = &a;
// // p2 = &b;  // ❌ Error: Cannot change pointer address
// *p2 = 30;    // ✅ Allowed: Can modify value

// // 3. Constant pointer to a constant value
// const int* const p3 = &a;
// // p3 = &b;  // ❌ Error: Cannot change pointer address
// // *p3 = 40; // ❌ Error: Cannot modify value
