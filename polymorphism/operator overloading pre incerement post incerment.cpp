#include <iostream>
using namespace std;

class Counter {
    int value;
public:

    Counter() {}
    Counter(int val) : value(val) {}  //  constructor initialization

    void display() { cout << "Value: " << value << endl; }

    // Postfix increment overloading
    Counter operator++(int) {
        Counter temp = *this; // Store original object
        value++; // Increment value
        return temp; // Return original object before increment
    }

    // Prefix increment overloading
    Counter& operator++() {
        ++value; // Increment value
        return *this; // Return updated object
    }
};

int main() {
    Counter obj(10);
    ++obj; // Calls the prefix increment
    obj.display(); // Output: Value: 11
    obj++;  // Calls the postfix increment
    obj.display(); // Output: Value: 12

    Counter obj1;
    obj1=++obj;
    obj1.display();
    obj.display();
}
