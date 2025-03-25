#include<iostream>
using namespace std;


//The pointer itself is constant (cannot be changed to point to another address).
//The data it points to can be modified.

int main()
{
    int a = 10;
    int b = 20;
    int *const ptr = &a;  // Must initialize
    cout<<*ptr<<endl;
    *ptr = 15;  // ✅ Allowed: Can modify the value
    //ptr = &b;   // ❌ Error: Cannot change pointer itself
    cout<<*ptr<<endl;
    return 0;
}