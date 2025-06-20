// Template Metaprogramming (TMP) in C++ is a technique where templates are used to perform computations at compile time rather than runtime.
//  It’s a powerful but advanced feature of C++ that allows you to write code that the compiler executes during compilation. 
// This can lead to faster runtime execution and more flexible, type-safe programs.


// ✅ Key Uses:
// Compile-time computations
// Type selection and transformation
// Static assertions
// Optimization (e.g., loop unrolling)
// Traits and policy-based design



// 1.) constant evaluation using template 

#include<iostream>

template<int N>
struct Factorial {
    static const int value = N * Factorial<N - 1>::value;   // recursive template initialization 
};

template<>
struct Factorial<0> {
    static const int value = 1;
};

// Usage
int main() {
    std::cout << Factorial<5>::value; // Output: 120
}



// if we do factorial<-1>:: value this will leads to compile time error 
// here it is static which makes it class level member 
// const allow the value to not change which allow compile time optimization 



//2.) conditional logic at compile time(if else)



// classic way 



#include<iostream>

using namespace std;


template<bool condition  , typename truetype , typename falsetype>
struct select
{
    typedef truetype type;
};

template<typename truetype ,typename falsetype>
struct select <false,truetype,falsetype>
{
    typedef falsetype type;     // can also use using insetad of typedef  using type=falsetype 
};

int main()
{
    select<true,int ,double>::type a=42;
    select<false,int,double>:: type b=2.41;
    std::cout << "a (int): " << a << "\n";
    std::cout << "b (double): " << b << "\n";
    return 0;
}


// USING STD::CONDITION 

#include <iostream>
#include <type_traits>

int main() {
    // If condition is true, type is int, else double
    std::conditional<true, int, double>::type a = 42;
    std::conditional<false, int, double>::type b = 3.14;

    std::cout << "a (int): " << a << "\n";
    std::cout << "b (double): " << b << "\n";

    return 0;
}


// SFINAE

// SFINAE (Substitution Failure Is Not An Error) is a powerful feature in C++ template metaprogramming that allows function or
// class template overload resolution to ignore invalid substitutions, rather than producing a hard compilation error.


// When the compiler substitutes types or expressions into a template, if substitution leads to an invalid type or expression, 
// instead of issuing an error, the compiler simply removes that candidate from overload resolution. It allows other overloads
// or specializations to be considered instead.


#include <iostream>
#include <type_traits>

// // Only enabled if T is an integral type
// template <typename T>
// typename std::enable_if<std::is_integral<T>::value, void>::type
// func(T val) {
//     std::cout << val << " is integral\n";
// }

// // Only enabled if T is not an integral type
// template <typename T>
// typename std::enable_if<!std::is_integral<T>::value, void>::type
// func(T val) {
//     std::cout << val << " is not integral\n";
// }

// int main() {
//     func(10);      // int -> integral
//     func(3.14);    // double -> not integral
// }





// using constexpr

// cpp 17

template<typename T>
void func(T val) {
    if constexpr (std::is_integral<T>::value) {
        std::cout << "Integral\n";
    } else {
        std::cout << "Not integral\n";
    }
}



//🧠 Use if constexpr when you want branching inside a function based on type traits;
// use SFINAE for selecting or disabling entire functions/types.





// VARIADIC TEMPLATE IN TMP
template<typename... Args>
struct Count {
    static const int value = sizeof...(Args);
};

int main() {
    std::cout << Count<int, double, char>::value;  // Output: 3
}
