#include<iostream>
using namespace std;

// The simple idea is to pass the data type as a parameter so that we don’t need to write the same code for different data types. 
// C++ adds two new keywords to support templates: ‘template’ and ‘typename’. 

// Templates are expanded at compiler time. This is like macros. 
// The difference is, that the compiler does type-checking before template expansion. 
// The idea is simple, source code contains only function/class, but compiled code may contain multiple copies of the same function/class. 


//FUNCTION TEMPELATE

// template <typename T>T mymax(T x ,T y)
// {
//     return (x>y)?x:y;
// }

// int main()
// {
//     cout<<mymax<int>(3,7)<<endl;
//     return 0;
// }


// If the function is also present 

template <typename T> T display(T a) {
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



// --------------------------------------- TEMPLATE CLASS ----------------------------------------------------------------



#include<iostream>
using namespace std;


// template<typename T> is used to create the class of any data type 

// can also add multiple parameters to the template 


// setting the default as int and string 

template<typename T=int, typename U=string>
class box
{
private:
    T value;
    U name;
public:
    box(T val, U naam) : value(val), name(naam) {}  
    void show()
    {
        cout << "Value: " << value << ", Name: " << name << endl;
    }
};

int main()
{
    box<int, string> mybox(10, "IntegerBox");  
    mybox.show();

    box<float, char> myfloatbox(10.567, 'F');  
    myfloatbox.show();

    box<>defaultbox(1000,"shobhit");
    defaultbox.show();
    return 0;
}


// --------------------------------------------------------------------------VARIADIC TEMPLATE------------------------------------------------------------



#include <iostream>
using namespace std;

template <typename T, typename... Args>
void print(T first, Args... rest) {
    cout << first << " ";
    if constexpr (sizeof...(rest) > 0) // Recursively call if more arguments exist
        print(rest...);
}

int main() {
    print(1, 2.5, "Hello", 'A');
    return 0;
}
    




// Count function Arguments at Compile - Time


#include <iostream>
template<typename... Args>
void countArgs(Args... args) {
    std::cout << "Number of arguments: " << sizeof...(Args) << "\n";
    std::cout << "Number of values: " << sizeof...(args) << "\n";
}

int main() {
    countArgs(1, 3.14, "Hello");  // 3 types (int, double, const char*) 
    countArgs('A', true);         // 2 types (char, bool)
    countArgs();                  // 0 types (empty)
}



//Args = int, double, const char*
//args = values 1, 3.14, "Hello" 
//
//output
//3 
//


// Summing Numbers with Fold Expression(C++17)

#include <iostream>

template<typename... Args>
auto sum(Args... args) {
    return (args + ...); // Fold expression
    //Equivalent to arg1 + (arg2 + (arg3 + arg4))
}

//Works with :
//
//Any operator (+, *, << , &&, etc.)

int main() {
    std::cout << sum(1, 2, 3, 4) << "\n";    // Output: 10 (1+2+3+4)
    std::cout << sum(1.5, 2.5) << "\n";       // Output: 4 (1.5+2.5)
    std::cout << sum(10) << "\n";             // Output: 10 (single value)
    std::cout << sum() << "\n";               // Error: empty fold (won't compile)
}



// Lambdas + variadics(C++14 + c++17 ) :

#include <iostream>

    int main() {
    // Variadic lambda using 'auto...' (C++14+)
    auto sum_all = [](auto... xs) {
        return (xs + ...); // Fold expression (C++17)
        };

    std::cout << sum_all(1, 2, 3) << "\n";    // 6 (1+2+3)
    std::cout << sum_all(1.5, 2.5) << "\n";    // 4.0
    std::cout << sum_all(10) << "\n";          // 10 (single arg)
    // sum_all(); // Error: empty fold
}