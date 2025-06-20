#include<iostream>
using namespace std;


// the const keyword is used to define constants and enforce immutability.


// const variable 

//The const variable cannot be left un-initialized at the time of the declaration.
// If you try to initialize the const variable without assigning an explicit value then a compile-time error (CTE) is generated. 

// THEY BOTH ARE WRONG 
// const int var;
// const int var;
// var=10;


const int var=10;

// A const variable means its value cannot be changed after initialization.

int main()
{
   // var=20;   //value cannot be changed after initialization.
    cout<<var<<endl;
    return 0;
}