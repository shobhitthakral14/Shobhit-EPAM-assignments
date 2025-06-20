#include<iostream>
#include<memory>
using namespace std;


// Smart pointers in C++ are a feature introduced in C++11 that help manage dynamic memory automatically.
// They are part of the Standard Library's <memory> header and prevent memory leaks by ensuring proper deallocation of dynamically allocated objects.

// Issues with simple pointers are memory leak if we forget to delete ,
// dangling pointers if we want to acess the memory which is already freed,
// double deletion means deleting the same pointer twice 




// smart pointers deallocate memory automatically
// they are of 3 types unique weak shared 

//1.) UNIQUE POINTER 
 
// A unique_ptr owns a dynamically allocated object exclusively and ensures that the object is deleted when the unique_ptr goes out of scope.

// we cannot make copy of unique pointer
// instead we cangive ownership using the move


// class myclass
// {
//     public:
//     myclass()
//     {
//         cout<<"constructor invoked"<<endl;
//     }
//     ~myclass()
//     {
//         cout<<"destructor invoked"<<endl;
//     }
// };




int main()
{
    // unique_ptr<int>unPtr1=make_unique<int>(25);

    // //unique_ptr<int>unPtr2=unPtr1;    // this will give error 

    // unique_ptr<int>unPtr2=move(unPtr1);   // giving the ownership
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