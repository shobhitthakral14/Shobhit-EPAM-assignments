#include <iostream>
using namespace std;


//It is stored in global memory and not in an individual object’s memory.
// it must be defined outside the class 


class base {
public:
    static int x; // Declaration of static variable

    void show() {
        x+=10;
        cout << "x = " << x << std::endl;
    }
};

int base :: x = 10; // Definition and Initialization outside the class using return type classname scope resolution and the variable name

int main() {
    base obj1;
    base obj2;
    obj1.show();
    obj2.show();

    base::x = 20; // Modifying static variable

    obj1.show();

    // Since x is shared among all objects, modifying it in obj1 reflects in obj2.
    obj2.show();
    return 0;
}
