#include<iostream>
//Most of the standard C++ functions and classes are in the std namespace.
//But in large projects it is not recommended 
using namespace std;

//They improve code organization and readability.
// Use namespace aliases for long names.
//Namespaces prevent naming conflicts.

namespace outer{
    int var=10;
    int ans=10000;
    void fun()
    {
        cout<<"inside outer"<<endl;
    }

    // The resolution of namespace variables is hierarchical. 
    namespace inner {
        int val=50;
        int ans2=ans;
        void fun()
        {
            cout<<"inside inner"<<endl;
        }
    }
}

// Unnamed namespace is only valid within this file 
//Unnamed namespaces are the replacement for the static declaration of variables.

namespace {
    int variable =109;
}

// sometimes the name of namespace is too long 
// we can make the alias also my equalating


// If the namespace is nested then in the new declared namespace = namespace1::namespace2::namespace3


namespace MyLongNamespaceName {
    int data = 60;
}

namespace Short = MyLongNamespaceName;



int main()
{
    using namespace outer::inner;
    cout<<val<<endl;
    outer::fun();
    outer::inner::fun();
    cout<<variable<<endl;
    cout<<ans2<<endl;
    cout<<Short::data<<endl;
    cout<<MyLongNamespaceName::data<<endl;
    return 0;
}