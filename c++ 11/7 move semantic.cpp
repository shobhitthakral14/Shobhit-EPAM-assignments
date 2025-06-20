// Move semantics is a key feature introduced in C++11 that optimizes performance by transferring resources (like dynamic memory, file handles, etc.) from one object to another instead of copying them.
// It enables efficient handling of temporary objects and large data structures.

// When a temporary object or large object is returned from a function or passed as an argument, copying it can be expensive.
// Move semantics avoids deep copies by transferring ownership of resources.

// L value and R value

// | **Feature * *        | **L - value  Locator* *                                    | **R - value * *                                 
// | ------------------ - | ------------------------------------------------ - | -------------------------------------------- -  |
// | **Name * *           | Has a name                                         | Does not have a name                            |
// | **Variable Type * *  | All variables are L - values                       | R - value is a temporary value                  |
// | **Assignment * *     | Can be assigned values                             | Cannot be assigned values                       |
// | **Expressions * *    | Some expressions return L - values                 | Some expressions return R - values              |
// | **Persistence * *    | Persists beyond the expression                     | Does not persist beyond the expression          |
// | **Function Return * *| Functions that return by reference return L - value| Functions that return by value return R - value |
// | **Reference Type * * | Reference to L - value(L - value reference)        | Reference to R - value(R - value reference)     |




// l value means locator value 
// refers to an object that has aname and memory address (i.e., it persists).
// Can appear on the left or right side of an assignment.
// int x = 10;   // x is an lvalue
// x = 20;       // valid: x is on the left side
// int* p = &x;  // valid: x has an address


// l value reference can bind only to l value 
// declared using &

// int x=10;
// int &ref=x;    // here ref is a l value reference as it is binding to x which is a l value 





// r value means read value 

//A temporary value that does not have a memory address.
// Can appear only on the right side of an assignment.
// Cannot be assigned to.

// int x = 10 + 5;  // 10 + 5 is an rvalue
// int y = x * 2;   // x * 2 is an rvalue


 // But an l-value can bind to a const l-value reference
//    const int& r2 = 3;


// r value reference can only bind to r value 
// declared using && 

// int &&ref=5;   // 5 is a r value
// int x=10;
// int &&rref2=x+1;   // here x=1 is a r value 




// MOVE IN R VALUE 

// int x=10;
// int &ref=x;
// int &&ref1=x;   // it will give error as x is a l value and it is biding to r value refernce 
// so to overcome this force an lvalue to be treated as an rvalue using std::move();
// here move cast x to an r value which allow it to bind with ref1
// int &&ref2=std::move(x);



//std::move is basically just a fancy wrapper around static_cast that casts an lvalue to an rvalue reference.




// 
// Narendra Kodi 55 minutes 39 seconds
// So to answer my question, how many times will you constructor get called? One is STD move, second is returning local variable.
// Narendra Kodi 55 minutes 49 seconds
// 3rd is passing temporary object.









//L value and R value /* | **Feature * ... by Himanshu Pathak1


//L value and R value
/*
| **Feature * *        | **L - value  Locator* *                                    | **R - value * *                                 |
| ------------------ - | ------------------------------------------------ - | -------------------------------------------- -  |
| **Name * *           | Has a name                                         | Does not have a name                            |
| **Variable Type * *  | All variables are L - values                       | R - value is a temporary value                  |
| **Assignment * *     | Can be assigned values                             | Cannot be assigned values                       |
| **Expressions * *    | Some expressions return L - values                 | Some expressions return R - values              |
| **Persistence * *    | Persists beyond the expression                     | Does not persist beyond the expression          |
| **Function Return * *| Functions that return by reference return L - value| Functions that return by value return R - value |
| **Reference Type * * | Reference to L - value(L - value reference)        | Reference to R - value(R - value reference)     |

 

//R- value reference

 

| **Feature**                | **Description**                               |
| -------------------------- | --------------------------------------------- |
| **Definition**             | A reference created to a temporary            |
| **Represents**             | A temporary value                             |
| **Syntax**                 | Created with `&&` operator                    |
| **Can Bind To**            | Only R-values (temporaries)                   |
| **Cannot Bind To**         | L-values                                      |
| **Binding Rule**           | R-value references always bind to temporaries |
| **L-value Reference Rule** | L-value references (&) always bind to L-values    |

 

int&& ref=5+3
int& ref1=x;
*/

 

#include <iostream>

// Returns r-value
int Add(int x, int y) {
   return x + y;
}

// Returns l-value
int& Transform(int& x) {
   x *= x;
   return x;
}

// Print accepts l-value reference
void Print(int& x) {
   std::cout << "Lvalue : Print(int&)" << std::endl;
}

// Print accepts const l-value reference
void Print(const int& x) {
   std::cout << "Const Lvalue: Print(const int&)" << std::endl;
}

//Print accepts r-value reference
void Print(int&& x) {
   std::cout << "Rvalue : Print(int&&)" << std::endl;
}

int main() {
   // x is an l-value
   int x = 10;
   int y=x;
   int z=5+3;
   // ref is an l-value reference
   int& ref = x;

   // Transform returns an l-value
   int& ref2 = Transform(x);

   // rv is an r-value reference
   int&& rv = 8;

   // Add returns a temporary (r-value)
   int&& rv2 = Add(3, 5);

   // The following lines would cause an error because an l-value cannot bind to an r-value reference
    /*int var = 0;
    int &&r1 = var;*/

   // But an l-value can bind to a const l-value reference
   const int& r2 = 3;

   // Function call demonstrations
   int i = 10;
   Print(i);                        // L-value
   Print(10);                       // R-value
   Print(std::move(i));            // move() converts l-value into r-value
   Print(static_cast<int&&>(i));   // Explicit cast to r-value reference
   //Note:- static_cast and move both perform same operation ,
   //But we use it most of the time as move just avoid ambiguity and increase readability.


   return 0;
}

/*   🔄 What is std::move() ?   => std::mov... by Himanshu Pathak1
Himanshu Pathak1
29-05 18:03

/*

 

🔄 What is std::move() ?

 

=> std::move() is a standard library function defined in the <utility> header that casts an object to an r - value reference.
=> It does not actually move anything . It simply enables move semantics by converting an l - value into an r - value, so that the move constructor or move assignment operator can be used.
=> It's mainly used to avoid expensive deep copies (e.g., for containers, strings, or user-defined types with dynamic memory).
=> reinitialization is must after move a Lvalue.
=> It is also used for non copy operation where function only provides move operation.
*/

 

//#include <iostream>
//#include <string>
//#include <utility>
//#include<vector>
//
//void PrintArr(std::vector<int>&& v){
//    int n = v.size();
//    for (auto& i : v) {
//        std::cout << i << " ";
//    }
//}
//int main() {
//    std::string a = "Hyderabad";
//    std::string b = std::move(a); // move constructor is used
//    std::cout << "a: " << a << std::endl; // a is now in a valid but unspecified state
//    std::cout << "b: " << b << std::endl; // "Hyderabad"
//
//
//    std::vector<std::string> v;
//    v.emplace_back("C++ session"); // construct string directly in vector,avoiding temporaries.
//    v.push_back("CopyCreation"); // it create copy then move copy into container.
//
//    std::vector<int> arr = { 1,2,3,4,5 };
//    PrintArr(std::move(arr));
//    std::cout << std::endl;
//    //Print of array elements give us error because after move ,reinitialization is must to access those variables.
//    std::vector<int> arr2 = std::move(arr);
//    for (int i = 0; i < arr.size(); i++) {
//        std::cout << arr[i] << " ";
//    }
//
//
//}

 

// Why Move Semantics? /*  => Eliminate... by Himanshu Pathak1

// Why Move Semantics?
/* 
=> Eliminate unnecessary copying in c++ to boost speed and efficiency.
=> Improve Performance especially when handling large and complex objects by enabling the transfer of resources rather than costly duplication.

 

=>this all achieved through Lvalue ,Rvalue ,Rvalue Reference and the utility function std::move.

 

 

//Introduction...

 

//In C++, move semantics is a feature introduced in C++11 that allows resources to be efficiently transferred from one object to another, instead of copying them.
//This is particularly useful for expensive operations like managing dynamic memory, file handles, or other system resources.
//Allow us to avoid unnecessary copy of objects when working with temporary object.

 

//Why Move Semantics?

 

//When an object is copied, a deep copy is typically performed, which means duplicating all resources.However,
//in some cases(like returning objects from functions), creating a copy is wasteful.Move semantics allows transferring ownership of resources instead of duplicating them.

 

//When are Move Semantics Used ?

 

//Returning objects from functions(avoid unnecessary copies).
//When passing temporary objects.
//Optimizing large data structures like vectors, strings, etc.

 

 

Copy & Move Semantics : -

 

*Copy is implemented through copy constructor
* Copy of the object state is created
* Wasteful in case copy is created from a temporary
* Instead, the state can be moved from the source object
* Implemented through move semantics

 

Resource Management :-
   * Some classes own a resource
   * This resource may be a pointer, file handle, socket, etc.
   * Such resources may be acquired in the constructor
   * Subsequently, you have to decide the action in case objects of such classes are copied, moved or destroyed
   * E.g. on destruction, the resource must be released to avoid leaks
   * Similarly, on copy or move the resource must be handled accordingly
*/

 

//Move Constructor and Move Copy Assignment...

 

//#include <iostream>
//using namespace std;
//
//class A {
//private:
//    int* ptrArr;
//public:
//    A() : ptrArr(new int[5]) {
//        for (int i = 0; i < 5; ++i) {
//            ptrArr[i] = i + 1;
//        }
//        cout << "default constructor called" << endl;
//    }
//
//    // Copy Constructor (Deep Copy)
//    A(const A& other) : ptrArr(new int[5]) {
//        cout << "copy constructor called" << endl;
//        for (int i = 0; i < 5; ++i) {
//            this->ptrArr[i] = other.ptrArr[i];
//        }
//    }
//
//    // Move Copy Constructor
//    A(A&& other) noexcept : ptrArr(other.ptrArr) {
//        cout << "move constructor called" << endl;
//        other.ptrArr = nullptr; // Transfer ownership
//    }
//
//    // Copy Assignment Operator
//    A& operator=(const A& other) {
//        cout << "Copy Assignment Overload" << endl;
//        if (this != &other) {
//            delete[] ptrArr;
//            this->ptrArr = new int[5];
//            for (int i = 0; i < 5; ++i) {
//                ptrArr[i] = other.ptrArr[i];
//            }
//        }
//        return *this;
//    }
//
//    // Move Assignment Operator
//    //noexcept defines that function can't throw error
//    A& operator=(A&& other) noexcept {
//        cout << "Move Assignment Overload" << endl;
//        if (this != &other) {
//            delete[] ptrArr;
//            this->ptrArr = other.ptrArr;
//            other.ptrArr = nullptr;
//        }
//        return *this;
//    }
//
//    void display() {
//        cout << "print call" << endl;
//        for (int i = 0; i < 5; ++i) {
//            cout << ptrArr[i] << " ";
//        }
//        cout << endl;
//        cout << endl;
//    }
//
//    virtual ~A() {
//        delete[] ptrArr;
//        cout << "destructor is called" << endl;
//    }
//};
//
//int main() {
//    A a;
//    a.display();
//
//    // Copy constructor
//    A b = a;
//    b.display();
//
//    // Move constructor
//    A c = std::move(b);
//    c.display();
//    //b.display();
//
//    A d;
//    //Copy Assignment
//    d = a;
//    d.display();
//
//    A e;
//    // Move copy assignment
//    e = std::move(a);
//    e.display();
//}

 

 

//move constructor with vector reallocation or resizing.

 

//#include <iostream>
//#include <vector>
//
//class MyClass {
//public:
//    int* data;
//
//    MyClass(int val) {
//        data = new int(val);
//        std::cout << "Constructor: " << *data << std::endl;
//    }
//
//    // Copy constructor
//    MyClass(const MyClass& other) {
//        if(other.data!=nullptr) //********************
//        data = new int(*other.data); 
//        std::cout << "Copy Constructor: " << *data << std::endl;
//    }
//
//    // Move constructor
//    MyClass(MyClass&& other) noexcept {
//        data = other.data;
//        other.data = nullptr;
//        std::cout << "Move Constructor\n";
//    }
//
//    ~MyClass() {
//        if (data) {
//            std::cout << "Destructor: " << *data << std::endl;
//            delete data;
//        }
//    }
//};
//
//int main() {
//    std::vector<MyClass> vec;
//
//    vec.reserve(2);  // Avoid reallocation for first 2
//    vec.push_back(MyClass(1));
//    vec.push_back(MyClass(2));
//
//    std::cout << "--- Triggering Reallocation ---\n";
//    vec.push_back(MyClass(3)); // Causes reallocation, moves/copies objects
//
//    return 0;
//}
//// If we did not use noexcept in our move constructor then we can see that order of destructors are not deallocating in reverse order of object creation due to vector implementation and it varies compiler to compiler.

 

 