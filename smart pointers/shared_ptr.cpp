#include<iostream>
#include<memory>
using namespace std;


// A shared_ptr is a smart pointer in C++ that allows multiple smart pointers to share ownership of the same dynamically allocated object.
// it’ll maintain a Reference Counter using the use_count() method. 

// When a shared_ptr is created, the reference count is 1.
// When a shared_ptr is copied, the reference count increases.
// When a shared_ptr is destroyed (or reset), the reference count decreases.
// When the reference count reaches 0, the object is automatically deleted.

class Test {
    public:
        Test() { cout << "Constructor called\n"; }
        ~Test() { cout << "Destructor called\n"; }
        void show() { cout << "Hello from Test\n"; }
    };
    


// PASSING SHARED POINTER TO THE FUNCTION

    // 1.) PASS BY VALUE 

     void print(shared_ptr<int>p)
     {
        cout<<"value : "<<*p<<endl;
     }

     // 2.) PASS BY REFERENCE 
     
     // to avoid unnecessary copies
     void printr(const shared_ptr<int>&p)
     {
        cout<<"value referenced: "<<*p<<endl;
     }




    int main() {
        shared_ptr<Test> ptr1 = make_shared<Test>(); // Reference count = 1
        shared_ptr<Test> ptr2 = ptr1; // Reference count = 2
        // here as it is new so constructor and destructor of ptr3 will be called also 



        // it is preferred to use make_shared<T> rather than new as it is simple , exception safety , efficient memory allocation 
        shared_ptr<Test> ptr3(new Test());
        ptr3->show();
        ptr3=ptr1;  // Reference copunt = 3
        cout << "Reference Count: " << ptr1.use_count() << "\n"; // 3
        ptr2.reset();  // Reference count = 2
    
        cout << "Reference Count after ptr2 reset: " << ptr1.use_count() << "\n"; // 2
        return 0; // Destructor is called when the last shared_ptr goes out of scope



        // resetting the new value does not decrease the use count 
        shared_ptr<int> p1 = make_shared<int>(5);
        p1.reset();
        cout<<p1.use_count()<<endl;
        p1.reset(new int(10));
        cout<<p1.use_count()<<endl;

        // passing shared pointer to the function

        shared_ptr<int>st1=make_shared<int>(1000);
        print(st1);
        printr(st1);
        
    }