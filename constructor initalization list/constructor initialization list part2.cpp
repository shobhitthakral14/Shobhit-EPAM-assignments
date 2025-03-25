#include <iostream>
using namespace std;




class Base {
    int x;
public:
    Base(int a) : x(a) {
        cout << "Base class initialized with x: " << x << endl;
    }
};

class Derived : public Base {
    int y;
public:
    Derived(int a, int b) : Base(a), y(b) {
        cout << "Derived class initialized with y: " << y << endl;
    }
};

int main() {
    Derived obj(10, 20);
    return 0;
}
