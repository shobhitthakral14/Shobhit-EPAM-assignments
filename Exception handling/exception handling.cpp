#include<iostream>
using namespace std;

//In cpp exception is the runtime anamolies or abnormal conditions that occur in the execution of the program 
//Synchronous: Exceptions that happen when something goes wrong because of a mistake in the input data or when the program is not equipped to handle the current type of data it’s working with, such as dividing a number by zero.
//Asynchronous: Exceptions that are beyond the program’s control, such as disc failure, keyboard interrupts, etc.

//  using try throw catch 

// scenarios 

// Division by zero
// Out-of-bounds array access
// Memory allocation failures
// Invalid input
// File handling errors



// try statement allows you to define a block of code to be tested for errors while it is being executed.
// Throw throughs it to the catch block if the error occurs and then return the throw's value
// If an exception is thrown and not caught anywhere, the program terminates abnormally. 


// multiple catch blocks 
void testexception(int num)
{
    try
    {
        {
            if(num==0)
            throw "String exception:";

            if(num==1)
            throw 1;

            if(num==2)
            throw 2548;
        }

    }
    catch(const char* msg)
    {
        cout<<"caught exception :"<<msg<<endl;
    }
    catch (int num )
    {
        cout<<"caught integer exception "<<num<<endl;
    }
    catch(...)
    {
        cout << "Caught an unknown exception!" << endl;
    }
    
}

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
            throw "division by zero not allowed";
        }
        res=num/den;
        cout<<"result"<<res<<endl;
    }


    // for string or char it should be const char * and in case of int must be int 
    // in catch the parameter must be the throw's datatype
    // if dont't know the return type of the exception add ... in the catch's arugment this is known as catch all block 
    catch(const char *msg)
    {
        cout<<"exception :  "<<msg <<endl;
    }

    testexception(0);
    testexception(1);
    testexception(2);
    return 0;
}