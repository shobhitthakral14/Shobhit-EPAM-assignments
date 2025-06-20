// A functor (function object) in C++ is any object that can be called like a function or function pointers.
// This is achieved by overloading the operator(). Functors are widely used in STL algorithms, custom sorting, and stateful operations.]

#include<iostream>
using namespace std;


// Basic example of functors

// A simple example of a functor is a class that overloads the operator().

class Multiplby
{
    int factor;
    public:
    Multiplby(int f) :factor(f) {}
    int operator() (int value) const
    {
        return value*factor;
    }
};

int main()
{
    Multiplby times2(2); // Functor instance to multiply by 2
    cout<< times2(5)<<endl; // Calls operator ()
    return 0;

}
