#include<iostream>
using namespace std;

//A static function is a function that is associated with a class rather than an instance of the class means rather than to the object . 
//It can be used without creating an object of the class and can only access static members of the class.


// static function do not access the non static data members

// staticn functions stored in global memory 
 class math
 {
    public:
    static int add(int a ,int b)
    {
        return a+b;
    }

    void nonStaticFunction() {
        cout << "This is a non-static function!" << endl;
    }
 };


 // invoked in main using class::function name() in cpp
 // in java classname.function()

 int main()
 {
    cout<<"SUM : "<<math::add(6,8)<<endl;

    // object is to be created to use the non static functions
    math obj1;
    obj1.nonStaticFunction();

    return 0;
 }


//  use cases 
//  1.) utility functions means the functions that does not depend on the object specific data
//  2.) Factory Methods – Used to create and return instances (ClassName::createInstance()).
//  3.)  Global Counters/Trackers – To keep track of objects created.