#include<iostream>
using namespace std;



// The static keyword in C++ has different meanings depending on where and how it is used. It plays a crucial role in memory management, scope control, and access restrictions.


//1.) STATIC LOCAL VARIABLE

//	Retains value across function calls unlike regular functions reinitalized on each call 
//  storage of these variable exists throughout the program 


// They retain values between function calls and are initialized only once.
// Supported in C/C++ but not directly in languages like Python or Java.
// Useful for counting, caching, and maintaining state.
void counter()
{
    // IF IT IS NOT INITALIZED IT WILL BE 0
     static int ans=9;
     ans++;
     cout<<ans<<endl;
}


int main()
{
    counter();
    counter();
    counter();
    return 0;
}