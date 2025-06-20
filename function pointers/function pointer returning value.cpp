#include<iostream>

using namespace std;

// function returning a value
int square(int x)
{
    return x*x;
}

int main()
{
    // declaring a function pointer of int 
    int (*funcPtr)(int );  // Declares a function pointer that returns int and takes an int parameter.
    funcPtr=square; 
    cout<<funcPtr(5)<<endl; //funcPtr(5); → Calls square(5).
    return 0;
}