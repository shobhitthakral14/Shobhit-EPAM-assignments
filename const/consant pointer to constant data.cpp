#include<iostream>
using namespace std;

int main()
{
    const int a = 10;
    const int b = 20;
    const int *const ptr = &a;  // Must initialize
    //*ptr = 15;  // ❌ Error: Cannot modify value
    //ptr = &b;   // ❌ Error: Cannot change pointer

    return 0;
}


//Both the pointer and the data it points to are constant.
//You cannot modify the data or the pointer itself.