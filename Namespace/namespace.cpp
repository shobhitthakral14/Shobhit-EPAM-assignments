#include<iostream>
using namespace std;

// A namespace in C++ is a container that allows grouping of logically related identifiers
// (such as variables, functions, and classes) under a specific name.

//Example, you might be writing some code that has a function called xyz() and there is another library available which is also having same function xyz(). 
//Now the compiler has no way of knowing which version of xyz() function you are referring to within your code.

//A namespace is designed to overcome this difficulty and is used as additional information to differentiate similar functions, classes, variables etc.
// with the same name available in different libraries. 



// We can have two namespaces of the same name the second one is just the continuation of the first 
namespace Myname
{
    int var=10;
    void display()
    {
        cout<<"hello";
    }
}

// int main()
// {
//     Myname::var;
//     Myname::display();
//     return 0;
// }

// BY USING USING KEYWORD
// This can lead to name conflicts if multiple namespaces have the same identifier.
int  main()
{
    using Myname::var;
    // using namespace Myname;
    cout<<var<<endl;
    return 0;
}


//In each scope, a name can only represent one entity. So, there cannot be two variables with the same name in the same scope. Using namespaces,
// we can create two variables or member functions having the same name. 

