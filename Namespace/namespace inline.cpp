#include<iostream>
using namespace std;


//An inline namespace in C++ is a feature introduced in C++11 that allows a nested namespace to be automatically considered part of the outer namespace when looking up symbols.


namespace Library {
    inline namespace V2 {  // This is an inline namespace
        void show() {
            std::cout << "Library Version 2" << std::endl;
        }
    }

    namespace V1 {  // This is a normal namespace
        void show() {
            std::cout << "Library Version 1" << std::endl;
        }
    }
}

int main() {
    Library::show();  // Calls V2::show() automatically
    Library::V1::show();  // Calls V1 explicitly
    Library::V2::show();  // Can still call V2 explicitly
    return 0;
}
