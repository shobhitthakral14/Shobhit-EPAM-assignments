// The auto keyword in C++ is a type specifier that lets the compiler deduce the type of a variable from its initializer.
//  It’s especially useful when dealing with complex types, like iterators, lambdas, or template-heavy types


// auto is decided by compiler on compile time 

// auto x={1,2,3}  ==  intializer_list<int>


//Works with complex types like iterators, lambdas, pointers, etc.


// auto x = 5;              // int
// auto y = 5.0;            // double
// auto z = "hello";        // const char*     //{ 's', 'h', 'o', 'b', 'h', 'u', 'i', 't', '\0' }  one more than the actural size last one is null terminator 
// auto p = new int(10);    // int*
// auto& r = x;             // int&
// auto&& val = 5;          // int&& (rvalue reference)


const int x = 10;
auto a = x;        // int (not const)   // ignored until mentioned explicitly 
const auto b = x;  // const int


// pointers are deduced properly
int* ptr = &a;
auto p = ptr;      // int*


// used in range based loops 

// std::vector<int> v = {1, 2, 3, 4};
// for (auto it = v.begin(); it != v.end(); ++it)
//     std::cout << *it << " ";


//auto x;  // ❌ Error: no initializer
// compilation error – auto needs initializer to deduce the type.


// for reference also it needs to be explicitly mentioned 

// can be used with new also
auto p=new int(10);  // here p=int*


// auto as function return type 

auto add(int a, int b) {
    return a + b;  // return type deduced
}

// GENERIC LAMBDAS
// auto lambda = [](auto a, auto b) { return a + b; };
// std::cout << lambda(2, 3);      // 5
// std::cout << lambda(2.5, 1.5);  // 4.0




// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//   std::vector<int> v = {1, 2, 3};
// auto it = v.begin(); // std::vector<int>::iterator
// cout<<it<<endl;

//     return 0;
// }



// concept of cpp 17
// std::tuple<int, double> t = {1, 3.14};
// auto [a, b] = t; // a = int, b = double




const int x = 42;
auto a = x;        // int (const dropped)
auto& b = x;       // const int& (const preserved)
auto&& c = x;      // const int&  (universal reference binds to lvalue)
auto&& d = 5;      // int&&       (binds to rvalue)



// auto x = {1, 2, 3};        // std::initializer_list<int>
// auto y{1};                 // int
// auto z = {1};              // std::initializer_list<int>


int a[5]={1,2,3,4,5};
auto x=a;    //here x is int* array decays to pointer 



















