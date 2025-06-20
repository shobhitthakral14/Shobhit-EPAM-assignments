#include<iostream>
using namespace std;

// class can be defined inside the namespace or outside the namespace by using class namespacename:: classname 
// We cannot do both at the same time 

//
namespace hello
{
    class geek;
}

class hello::geek
{
    public:
    int var=10;
    void dislpay()
    {
        cout<<"Hello inside the class"<<endl;
    }
    void toshow();
};

void hello::geek::toshow()
{
    cout<<"Method outside the class "<<endl;
}



// ANOTHER CONCEPT OF NESTED 

// If both the method in the inner and the outer have the same name then if u want to call the function then use outer::fun() for the outer and outer::inner::fun() for the inner

// If we use using namespace outer only and called the fun() then fun() of the outer is called

// If we use using namespace outer::inner then the fun() of the inner is called 

// If we used both and call the fun() without mentioning it will give error 

// If we want to call then we must need to mention 

namespace outer
{
    void fun()
    {
        cout<<"Inside the outer of the namespace  "<<endl;
    }

    namespace inner 
    {
        void fun()
        {
            cout<<"Inside the inner "<<endl;
        }
    }
}



int main()
{
    hello::geek obj;
    cout<<obj.var<<endl;
    obj.dislpay();
    obj.toshow();

    using namespace outer;
    using namespace outer::inner;
    outer::fun();
    outer::inner::fun();
    return 0;
}



// ----------
// Anonymous(Unnamed) Namespaces

namespace {  // Only visible in this file
    int internalVar = 100;
    void helperFunc() { std::cout << "Helper!\n"; }
}

int main() {
    helperFunc();  // Can be used here but not in other files
    return 0;
}

// ----------
// Inline Namespaces

namespace Library {
    inline namespace v1 {  // Default version
        void api() { std::cout << "v1 API\n"; }
    }
    namespace v2 {         // New version (opt-in)
        void api() { std::cout << "v2 API\n"; }
    }
}

int main() {
    Library::api();        // Uses v1 (default)
    Library::v2::api();    // Explicitly uses v2
    return 0;
}