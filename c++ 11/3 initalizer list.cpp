// std::initializer_list is a powerful feature introduced in C++11 that allows a constructor or function to accept a braced list of values, like {1, 2, 3}.

//std::initializer_list<T> is a lightweight wrapper around a fixed-size array of const T elements.

// it usually contain the pointer to the first element and the size of the list 

// struct initializer_list {
//     const int* _array;
//     size_t _size;
// };


#include <initializer_list>
#include <iostream>
using namespace std;

void printList(initializer_list<int> list) {
    for (int value : list)
        cout << value << " ";
        cout << endl;
}

int main() {
    printList({1, 2, 3, 4, 5}); // calls the initializer_list version
}


//It creates a constant array internally; elements cannot be modified.
// It is not resizable 
// It cannot be null or empty like a pointer (though an empty list {} is valid).




// accessing elements 
// std::initializer_list<int> list = {1, 2, 3};
// for (auto it = list.begin(); it != list.end(); ++it)
//     cout << *it << " ";



// initializer_list vs Variadic Templates
// initializer_list is type-safe, all elements must be of the same type.

// It doesn't allow runtime-sized initialization.

// Less flexible than variadic templates, but more convenient in many cases.





//std::vector<int> v1{3};       // vector with 1 element of value 3
// std::vector<int> v2(3);       // vector with 3 default-initialized elements (0)  



// internally it is like 
// As a lightweight object containing a pointer to a constant array and a size.

//  must contain elements of same type 

// we cannot pass auto in initializer list initializer_list<auto>  X

auto x = 10;           // OK
auto y = {1, 2, 3};    // OK, but type is std::initializer_list<int>





//The array backing initializer_list is typically placed on the stack or in static memory, depending on the context. 
//It's not allocated on the heap, which is why the object is very lightweight.








// std::vector<int> vec = {1, 2, 3};
//std::vector<int> vec = std::initializer_list<int>{1, 2, 3};


///std::vector uses initializer_list only at the time of construction or assignment.

// After that, it manages its own dynamic memory, completely independent of the initializer list.

// You can then modify, resize, or manipulate the vector freely.




// USES 

// container initialization 
//std::vector<int> v = {1, 2, 3, 4};
// std::set<std::string> s = {"apple", "banana", "cherry"};



// 2.)Custom class constructors
// You can create constructors that accept initializer lists to allow users to initialize your class objects with brace-enclosed lists:
class MyClass {
public:
    MyClass(std::initializer_list<int> list) {
        for (auto val : list)
            std::cout << val << " ";
    }
};

MyClass obj = {10, 20, 30};  // prints: 10 20 30




//The underlying array backing an initializer_list lives as long as the list object itself — often it is created as a temporary in the caller scope.



// overload ambiguity

// void f(int) { std::cout << "int\n"; }
// void f(std::initializer_list<int>) { std::cout << "initializer_list\n"; }

// f(5);        // calls f(int)
// f({5});      // calls f(initializer_list<int>)
