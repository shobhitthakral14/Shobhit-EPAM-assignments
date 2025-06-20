// Smart pointers are wrapper classes around raw pointers that automatically manage the lifetime of dynamically allocated objects (memory management). 
//T hey help avoid manual delete calls and common bugs like memory leaks, dangling pointers, and double deletes.

// Smart pointers automate this, using RAII (Resource Acquisition Is Initialization) principle.

// in cpp there are 3 smart pointers in <memory> library


//1.) Unique pointers


//std::unique_ptr is a smart pointer introduced in C++11 that manages a dynamically allocated object with sole ownership—meaning no two unique_ptrs can own the same resource.
// canot be copied 
// can be moved 
// this ensures that only one unique pointer can own the resource at a time 
// Automatically deletes the resource when it goes out of scope.
// use when single owner exists 
// light weight and fast 


// #include <memory>  // required for unique_ptr
// std::unique_ptr<Type> ptr(new Type(args));




#include <iostream>
#include <memory>
using namespace std;

 class myclass
{
    public:
    myclass()
    {
        cout<<"constructor invoked"<<endl;
    }
    ~myclass()
    {
        cout<<"destructor invoked"<<endl;
    }
    void show()
    {
        cout<<"hello inside show"<<endl;
    }
};

int main()
{

    // unique_ptr<int>ptr1(new int(4));
    // unique_ptr<myclass>mc1(new myclass());
    // mc1->show();
    // unique_ptr<int>unPtr1=make_unique<int>(25);

    // //unique_ptr<int>unPtr2=unPtr1;    // this will give error as we are copying it

    // unique_ptr<int>unPtr2=std::move(unPtr1);   // giving the ownership
    // cout<<*unPtr2<<endl;
    // cout<<*unPtr1<<endl;  // now if want to use the previous created it will give exception

    // {

    //     unique_ptr<myclass>unptr1=make_unique<myclass>();
    // }





// unique_ptr can also manage dynamically allocated arrays:

    // unique_ptr<int []>arr=make_unique<int[]>(5) ;
    // arr[0]=10, arr[1]=20 , arr[2]=30 , arr[3]=50 ;
    // cout<<arr[0]<<endl;
    // cout<<arr[1]<<endl;
    // cout<<arr[2]<<endl;
    // cout<<arr[3]<<endl;



// Releasing without moving or giving ownership 

    // unique_ptr<int> ptr = make_unique<int>(50);

    // int* rawPtr = ptr.release();  // Releases ownership, now ptr is empty
    // cout << "Value: " << *rawPtr << endl;

    // delete rawPtr;  // ⚠️ Must manually delete it now



// Resetting 

    // unique_ptr<int>ptr1=make_unique<int>(10);
    // ptr1.reset(new int(20));
    // cout<<*ptr1<<endl;


// Accessing raw pointer

    // unique_ptr<int> ptr = make_unique<int>(100);
    // int* rawPtr = ptr.get();  // Get raw pointer without losing ownership
    // cout<<ptr<<endl;
    // cout << "Value: " << *rawPtr << endl;  // Output: 100

// Swapping 2 unique_pointers

    // unique_ptr<int> ptr1 = make_unique<int>(1);
    // unique_ptr<int> ptr2 = make_unique<int>(2);

    // ptr1.swap(ptr2);  // Now ptr1 owns 2 and ptr2 owns 1

    // cout << *ptr1 << " " << *ptr2 << endl;  // Output: 2 1


    return 0;
}



// GFG 

// If anything is created inside heap pointers are used 
// if we want to change the original place of the resource we need pointer to change the original resource 

// java c# has garbage collector to deallocate memory that can be used again and again 



// UNIQUE POINTER CAN BE USED IN VECTORS ALSO BUT WE MUST USE MOVE TO PUSH ELEMENTS AS THEY CANNOT BE COPIED 



// you can declare a unique_ptr first without initializing it, and then later assign it a dynamically created object.

//#include <iostream>
// #include <memory>
// using namespace std;

// int main() {
//     unique_ptr<int> ptr;   // Declaration only, currently nullptr

//     // Later assign a value:
//     ptr = make_unique<int>(42);  

//     cout << *ptr << endl;  // Output: 42

//     return 0;
// }





template<typename T>
class UniquePtr {
    T* ptr;

public:
    explicit UniquePtr(T* p = nullptr) : ptr(p) {}

    ~UniquePtr() {
        delete ptr;
    }

    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator=(const UniquePtr&) = delete;

    UniquePtr(UniquePtr&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;
    }

    UniquePtr& operator=(UniquePtr&& other) noexcept {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }
    T* get() const { return ptr; }
};
