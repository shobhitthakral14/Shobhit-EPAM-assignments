

// Static vs Member Function in C++

// | Feature                        | Static Function                                   | Member Function                               |
// | ------------------------------ | ---------------------------------------------     | -------------------------------------------- |
// | **Class Association**          | Belongs to the class itself                       | Belongs to an object (instance) of the class |
// | **`this` Pointer**             | ❌ Not available                                  | ✅ Available                                 |
// | **Access to Member Variables** | ❌ Only static members                            | ✅ All (static and non-static)               |
// | **Invocation Style**           | `ClassName::func()` or `object.func()`        | `object.func()`                              |
// | **Use Case**                   | Utility/helper methods, counters, factories   | Behavior depending on object state           |
// | **Memory Allocation**          | Exists independently of objects               | Exists per object                            |
// | **Polymorphism (virtual)**     | ❌ Not allowed                                | ✅ Allowed                                  |


#include <iostream>
using namespace std;

class MyClass {
    int a;
    static int count;

public:
    MyClass(int x) : a(x) { ++count; }

    static int getCount() {
        // cout << a; ❌ Can't access non-static
        return count;
    }

    void display() const {
        cout << "a = " << a << ", count = " << count << endl;
    }
};

int MyClass::count = 0;

int main() {
    MyClass obj1(5), obj2(10);
    obj1.display();
    cout << "Static Count: " << MyClass::getCount() << endl;
}


// static function cannot be virtual as virtual function depends on this pointer - static function dont have object context
// they cannot be override 
// they cannot access non static data members also as they don't have this pointer 
// it can be called by class name or by obj name also classname::fun()  or obj.fun()
// this cannot be passed to the static function as this is passed implicitly to non static function and refers to the calling obj 
// const cannot be applied to static member functions 
// static and non static can have same name but they must have different signature and static will not be virtual 
// static function can call the non static function only if it has access to that obj 

static void wrapper(MyClass& obj) {
    obj.display(); // OK via object
}
