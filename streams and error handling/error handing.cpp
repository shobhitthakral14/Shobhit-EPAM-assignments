// when we encounter the problems like:
// (1) when we demand the memory which is not available in the system so rather than terminating the program it handle it in handler
// (2) when we go beyond the capacity of container like array of vector so they will throw exception which need to be handle in handler block.


// In cpp exception is the runtime anamolies or abnormal conditions that occur in the execution of the program 
//  Exceptions that happen when something goes wrong because of a mistake in the input data 
// or when the program is not equipped to handle the current type of data it’s working with, such as dividing a number by zero.

// before exception handling cpp relied on error reporting techniques commonly used in C .
// Typical C functions report the failures through their return values and/or arguments


//(1)void *malloc()
// failure: can't allocate memory
// notification: return a null pointer

//(2) int printf()
// failure: can't format and print every item in its format list
// notification: return a negative value


//// How to use it ?
// (1) try:part of code that might have exception in future
// (2) catch: handler for exception
// (3) throw: exception from try is thrown using throw

// If an exception is thrown and not caught anywhere, the program terminates abnormally. 

// BASIC SYNTAX



// try {
//     // Code that might throw an exception
//     throw exception_type;
// }
// catch (exception_type e) {
//     // Handle the exception
// }

// built in types are int , char , const char *

#include <iostream>
#include<stdexcept>
using namespace std;

int main()
{

    // basic exception handling program
    try 
    {
        int den=0;
        int num=100;
        int res;
        if(den==0)
        {
            throw runtime_error("division by zero not allowed");     // like runtime error there are mamy more out_of_range , invalid_argument 
        }
        res=num/den;
        cout<<"result"<<res<<endl;
    }

    catch( const exception & e)    // if we dont use & only the base part of the exception is copied this is called object slicing 
    {
        cout<<"exception :  "<< e.what() <<endl;
    }

    return 0;
}



// ANOTHER PROGRAM 
// OUT OF RANGE ACCESSING 
#include<iostream>
#include<stdexcept>
#include<vector>
int main() {
	std::vector<int>nums;
	nums.push_back(1);
	

	try {
// 		std::cout << nums.at(1) << std::endl;    // at() throws std::out_of_range automatically if index is invalid.
// 		std::cout << "No Error" << std::endl;
		throw std::out_of_range("It is out of range ");  // Manual throw
	}
    // in the parameter it can be const std::out_of_range also 
	catch (const std::exception &e) {
		std::cout << "Its catched " << e.what()<< std::endl;
	}
	std::cout << "I am still alive" << std::endl;
	return 0;
}





// MULTIPLE EXCEPTION 
#include <iostream>
#include <string>

int main() {
    try {
        throw 1;
    }
    catch (const int& e) {
        std::cout << "Int Exception " << e<< std::endl;
    }

    try {
        throw 1.1;
    }
    catch (const double& e) {
        std::cout << "Double Exception " << e<< std::endl;
    }

    try {
        throw 1.1f;
    }
    catch (const float& e) {
        std::cout << "Float Exception " <<e<<  std::endl;
    }

    try {
        throw 'a';
    }
    catch (const char& e) {
        std::cout << "Char Exception " <<e<<  std::endl;
    }

    try {
        throw "char pointer exception";
    }
    catch (const char* e) {
        std::cout << "Char pointer Exception: " << e << std::endl;
    }

    try {
        throw std::string("std string exception");
    }
    catch (const std::string& e) {
        std::cout << "std::string Exception: " << e << std::endl;
    }

    try {
        throw true;  // no catch for bool, so will go to catch(...)
    }
    catch (...) {
        std::cout << "Caught by catch-all (...)" << std::endl;
    }

    return 0;
}



// Stack unwinding 
// concept always use only with exception handling mechanism
// when there is exception genrated then the fully constructed object of class or function goes out of scope in the sequence reverse to their creation

#include<iostream>
class A {
public:
	A() {
		std::cout << "In constructor of A" << std::endl;
	}
	~A() {
		std::cout << "In destructor of A" << std::endl;
	}
};
class B {
public:
	B() {
		std::cout << "In constructor of B" << std::endl;
	}
	~B() {
		std::cout << "In destructor of B" << std::endl;
	}
};

int main() {
	try {
		std::cout << "In try block" << std::endl;
		A a;
		B b;
		throw ("Exception thrown in try block of main");
	}
	catch (const char* e) {
		std::cout << "Exception " << e << std::endl;
	}
	std::cout << "Resume execution of main()" << std::endl;
	return 0;
}


// Destructors of all fully constructed local objects in the try block are called.
// Unwinding stops when the exception is caught.
// We cannot stop unwinding 
// manual cleanup cannot be done directly it can be done using setjmp/longjmp but it is unsafe and not recommended
// it is useful as it is used for resource cleanup and maintain stability 





// WHAT WILL HAPPEN IF A ERROR IS THROWN BUT NOT CATCHED ANYWHERE 

//What Happens When an Exception Is Thrown but Not Caught ?
//You throw an exception.
//
//No matching catch block is found(i.e., unhandled).
//
//The C++ runtime calls std::terminate().
//
//By default, std::terminate() calls std::abort().
//
//This immediately ends the program → no stack unwinding, destructors of local variables are not called.



//Code Example — Unhandled Exception → std::terminate() → Program Crash
#include <iostream>
#include <stdexcept>

class Test {
public:
    Test() { std::cout << "Constructor\n"; }
    ~Test() { std::cout << "Destructor\n"; } // Won't be called if terminate happens
};

void func() {
    Test t;
    throw std::runtime_error("Unhandled error in func()");
}

int main() {
    std::cout << "Starting main\n";
    func();  // Exception thrown but not caught
    std::cout << "End of main\n";
    return 0;
}
//output
//Starting main
//Constructor
//terminate called after throwing an instance of 'std::runtime_error'
//what() : Unhandled error in func()
//[1]    16827 abort(core dumped)
//Notice :
//Destructor is not called → stack unwinding is skipped.
//std::terminate() is invoked because no catch handles it.
//Then abort() → abrupt program termination with a core dump.



// customize std::terminate handler
#include<iostream>
#include<exception>
#include<stdexcept>

int main() {
	std::set_terminate([]() {
		std::cerr << "std::terminate() called,unhandled exception" << std::endl;
		std::abort();
		});

	throw 4;
return 0;
}



// EXCEPTION IN CONSTRUCTOR 

#include <iostream>
#include <stdexcept>  

class demo {
    int data;
public:
    demo() {
        std::cout << "Constructor started\n";
        try {
            throw std::runtime_error("Error in object creation");
        }
        catch (const std::runtime_error& e) {
            std::cout << "Exception caught in constructor: " << e.what() << std::endl;
            throw;  // Rethrow the exception to simulate failure
        }
    }

    ~demo() {
        std::cout << "Destructor of demo called\n";
    }

    void setdata(int d) { data = d; }
    int getdata() { return data; }
};

int main() {
    try {
        demo d;  // Constructor throws, object creation fails
        d.setdata(5);
        std::cout << d.getdata();
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Exception caught in main: " << e.what() << std::endl;
    }

    std::cout << "Program continued safely after handling exception\n";
    return 0;
}

//  Exceptions inside constructors are an important concept because constructors are responsible for object initialization.
//  If something goes wrong during this process, throwing an exception allows the program to abort the creation of an object safely.

// If there is error in constructor then the object is not created 
// and the partial which is created means the partial memory allocation will be cleaned up automatically


// Functions marked with noexcept must not throw exceptions.
// If a noexcept function throws an exception, the program will terminate.
// this improve the performance 





// RETHROW EXCEPTION 


#include <iostream>
#include <stdexcept>
using namespace std;

// Nested try-catch demonstration
void test() {
    try {
        throw "Initial Exception!";
    }
    catch (const char* msg) {
        cout << "Caught Exception inside test(): " << msg << endl;

        // Rethrow to outer catch block
        throw;
    }
}

int main() {
    // First try-catch block: division by zero check
    try {
        int num = 10;
        int den = 0;
        int res;

        if (den == 0) {
            throw runtime_error("Division by zero error!");
        }

        res = num / den; // (not executed)
        cout << "Answer: " << res << endl;
    }
    catch (const exception& e) {
        cout << "Exception caught in division block: " << e.what() << endl;
    }

    cout << "---- End of First Try Block ----\n" << endl;

    // Second try-catch block: nested exception demonstration
    try {
        test();
    }
    catch (const char* msg) {
        cout << "Exception rethrown and caught in main(): " << msg << endl;
    }

    cout << "---- End of Second Try Block ----\n" << endl;

    cout << "Program continues normally after both try-catch blocks." << endl;

    return 0;
}


// CUSTOM EXCEPTION IN CPP


#include <iostream>
#include <stdexcept>

using namespace std;

class MyException : public exception {
    int a;
public:
    MyException(int num) : a(num) {}

    const char* what() const noexcept override {
        return "Custom Exception";
    }

    int getErrorCode() const {
        return a;
    }
};

int main() {
    try {
        int num = 10;
        int den = 0;
        int res;

        if (den == 0) {
            throw MyException(10001);
        }

        res = num / den;
        cout << "Answer: " << res << endl;
    }
    catch (MyException& e) {
        cout << "Exception Code: " << e.what() << endl;
        cout << "Exception Code: " << e.getErrorCode() << endl;
    }

    return 0;
}

