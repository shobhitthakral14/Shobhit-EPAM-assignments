#include<iostream>
#include<stdexcept>
using namespace std;


//nest
void test() {
    try {
        throw "Initial Exception!";
    }
    catch (const char* msg) {
        cout << "Caught Exception: " << msg << endl;
        // if this throw is not present then there is no nesting in the block 
            throw;  // Rethrowing exception
    }
}

int main()
{
    try{
        int num=10;
        int den=0;
        int res;
        if(den==0)
        
        // this is only for the char catch 
        {
            throw runtime_error("error occurs");
        }
        res=num/den;
        cout<<"answer"<<res<<endl;
    }
    catch(const exception& e)
    {
        cout<<"exception "<<e.what()<<endl;
    }

    
    // nested exception handling 
    try {
        test();
    }
    catch (const char* msg) {
        cout << "Exception rethrown and caught again: " << msg << endl;
    }
    return 0;
}
