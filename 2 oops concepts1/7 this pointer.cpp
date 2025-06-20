// In C++, the this pointer is an implicit pointer available in non-static member functions of a class. 
// It refers to the calling object — the object for which the member function is currently invoked.

class Demo {
    int x;
public:
    void setX(int x) {
        this->x = x; // Resolving ambiguity using this pointer
    }
};


//When local variables or function parameters have the same name as class members, this-> helps differentiate.  

// not present in static function as static function don't belong to an object 


// used in method chaining
#include<iostream>
class Demo {
    int a;
public:
    Demo& setA(int a) {
        this->a = a;
        return *this;
    }
    void show() {
        std::cout << "a = " << a << "\n";
    }
};

int main() {
    Demo d;
    d.setA(10).show(); // Method chaining
}



// we cannot assign another object address to this as this is a const pointer -its value(address) cannot be changed

// this can be dereferrenced to give you the current object *this

// it is useful in method chaining and operator overloading 
