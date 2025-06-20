// A constructor with a single parameter is particularly prone to implicit conversions. explicit is most useful in such cases.
#include<iostream>
using namespace std;
class Test 
{
    public:
         Test(int x) { cout<<"Inside Constructor"; } // Prevents implicit conversion
};
    
    int main()
     {
        Test t1 = 10; // Error: Implicit conversion is prevented
        Test t2(10); // Works fine
        return 0;
    }
    