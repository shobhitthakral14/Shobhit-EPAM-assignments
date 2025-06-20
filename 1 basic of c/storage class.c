// In C, storage classes define the scope (visibility), lifetime (how long a variable exists), and linkage 
//(access across files) of variables and functions.
// There are four main storage classes in C:


// auto 
// register
// static 
// extern 

// | Storage Class | Scope      | Lifetime       | Linkage       | Notes                                 |
// | ------------- | ---------- | -------------- | ------------- | ------------------------------------- |
// | `auto`        | Local      | Block          | None          | Default for local vars                |
// | `register`    | Local      | Block          | None          | May use CPU register, no & allowed    |
// | `static`      | Local/File | Entire program | None/Internal | Retains value / File-level visibility |
// | `extern`      | Global     | Entire program | External      | Declares external variables/functions |




// differnce between struct and class

// | Use `struct` when...                        | Use `class` when...                        |
// | ------------------------------------------- | ------------------------------------------ |
// | You want a **simple data structure**        | You’re building an **OOP model**           |
// | All members should be **public by default** | You want **encapsulation** and **control** |
// | You want to maintain **C compatibility**    | You need **access control & abstraction**  |


// memory management in c 

// | Function    | Header       | Description                           |
// | ----------- | ------------ | ------------------------------------- |
// | `malloc()`  | `<stdlib.h>` | Allocates raw memory (uninitialized)  |
// | `calloc()`  | `<stdlib.h>` | Allocates and zero-initializes memory |
// | `realloc()` | `<stdlib.h>` | Resizes previously allocated memory   |
// | `free()`    | `<stdlib.h>` | Frees previously allocated memory     |

// malloc 

// dont initalize it 
// return NULL if allocation fails 
// int* arr = (int*) malloc(5 * sizeof(int));  // Allocates space for 5 integers


// calloc 
//int* arr = (int*) calloc(5, sizeof(int));   // Initializes to zero


//  realloc

// arr = (int*) realloc(arr, 10 * sizeof(int));  // Resize to hold 10 integers

// might move memory to new location 


// structure and union 

// | Feature            | `struct`                                         | `union`                                                       |
// | ------------------ | ------------------------------------------------ | ------------------------------------------------------------- |
// | **Memory**         | Each member has its **own memory space**         | All members **share the same memory location**                |
// | **Size**           | Sum of sizes of all members (+ padding)          | Size of the **largest** member                                |
// | **Modify Members** | All members can hold values **at the same time** | Only **one member** holds a valid value at a time             |
// | **Use Case**       | Used when all members are needed simultaneously  | Used to **save memory** when only one value is used at a time |
// | **Initialization** | All members can be initialized at once (C99)     | Only the **first member** can be initialized                  |



// PADDING 

// | Concept  | Description                                          |
// | -------- | ---------------------------------------------------- |
// | Padding  | Extra bytes added to align data in memory            |
// | Purpose  | Improve CPU access efficiency and avoid misalignment |
// | Problem  | Increases structure size unnecessarily               |
// | Solution | Reorder members, or use `#pragma pack` carefully     |


// #pragma pack(1)
// struct Packed {
//     char a;
//     int b;
//     char c;
// };
// #pragma pack()


////-A preprocessor directive in C++ is a special instruction that is processed before the actual compilation of the code begins.
//-These directives start with the # symbol and are handled by the preprocessor, which performs tasks like
//including files, defining macros, and conditionally compiling code.-.

// macro 
#define pi 3.14
#undef pi 

#define name "shobhit"

#define square(a) a*a

// multi line macro 

// multiple lines of code using \
//#define PRINT_VALUES(a, b) \
//    std::cout << a << " " << b << std::endl;

//----Advantages of Macros---
//1.Code Reusability 
//2.Enhanced Readability 
//3.faster than regular functions

// DISADVANTAGES 
//Lack of Type Safety 
//Debugging Challenges 