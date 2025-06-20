#include<iostream>
using namespace std;

class test
{
    public:
    test(int num) 
    {
        if(num==0)
        {
            throw runtime_error("constructor error ");
        }
    }
};

int main()
{
    try {
        test obj(0);
    }
    catch (const exception&e)
    {
        cout<<"caught exception "<<e.what()<<endl;
    }
    return 0;
}


// if in a class a constructor is present and a destructor is present and the object is created and 
// then it is checked in the try block then first the constructor is called then destructor and then the 
// exception handling occurs this is called stack unwinding 

//Functions marked with noexcept must not throw exceptions.
// If a noexcept function throws an exception, the program will terminate.
// this improve the performance 