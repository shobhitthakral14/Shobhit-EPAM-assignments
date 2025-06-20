// In C++, custom deleters are functions or function objects (functors or lambdas) that you can provide to smart pointers 
//(especially std::shared_ptr and std::unique_ptr) to customize how an object is destroyed when the smart pointer goes out of scope.

//  Why Use a Custom Deleter?
// Special resource cleanup (e.g., closing files or freeing memory from C-style APIs).

// Shared ownership of resources with different destruction logic.

// Arrays with unique_ptr (needs special deleter).



// CUSTOM DELETER WITH UNIQUE_PTR 
#include <iostream>
#include <memory>

struct CustomDeleter {
    void operator()(int* ptr) const {
        std::cout << "Custom delete (functor)\n";
        delete ptr;
    }
};

int main() {
    std::unique_ptr<int, CustomDeleter> up(new int(42));
}


// CUSTOM DELETER FOR UNIQUE_PTR<T[]>

// unique_ptr<T[]> automatically uses delete[], but if you want a custom deleter:


auto arrDeleter = [](int* p) {
    std::cout << "Deleting array\n";
    delete[] p;
};
std::unique_ptr<int[], decltype(arrDeleter)> arr(new int[5], arrDeleter);





// CUSTOM DELTER WITH SHARED_PTR
#include <iostream>
#include <memory>

void customDelete(int* ptr) {
    std::cout << "Shared_ptr custom deleter\n";
    delete ptr;
}

int main() {
    std::shared_ptr<int> ptr(new int(30), customDelete);
    std::cout << *ptr << std::endl;
}





// CUSTOM DELETER FOR ARRAYS 

#include <iostream>
#include <memory>

int main() {
    std::shared_ptr<int> arr(new int[5]{10, 20, 30, 40, 50}, [](int* p){
        std::cout << "Deleting shared array\n";
        delete[] p;
    });

    std::cout << arr.get()[2] << "\n"; // Accessing third element
}




// If we don’t provide a custom deleter in smart pointers, C++ will use the default deleter, which:
// Calls delete for std::unique_ptr<T>

// Calls delete[] for std::unique_ptr<T[]>

// Calls delete for std::shared_ptr<T>




//FILE* f = fopen("data.txt", "r");
// std::shared_ptr<FILE> file(f); // ❌ WRONG — will call delete on FILE*

//This results in crashing or resource leak, since delete doesn't know how to free a FILE*.


// std::unique_ptr<int> ptr(new int[5]); // ❌ WRONG — uses delete instead of delete[]
// This leads to undefined behavior, because delete is used on a memory block allocated with new[].



// Use Case	Valid?	Notes
// shared_ptr<T> arr[N];	✅	Array of smart pointers
// shared_ptr<T[]>	⚠️	Not supported directly
// shared_ptr<T>(new T[])	❌	Calls delete instead of delete[]
// shared_ptr<T>(new T[], custom)	✅	Use custom deleter
// vector<shared_ptr<T>>	✅	Safer and flexible


// std::shared_ptr<int> arr(new int[5], [](int* p){
//     std::cout << "Custom delete[]\n";
//     delete[] p;
// });
// std::shared_ptr<std::vector<int>> vec = std::make_shared<std::vector<int>>(5);
// 










// ✅ Can weak_ptr point to arrays?
// Technically yes — but only indirectly.

// Since shared_ptr<T[]> does not exist, you cannot have:

// cpp
// Copy
// Edit
// std::weak_ptr<int[]> wp;  // ❌ invalid, no shared_ptr<int[]> support
// Instead, you might do:

// cpp
// Copy
// Edit
// std::shared_ptr<int> sp(new int[5], [](int* p) {
//     std::cout << "Custom deleter for array\n";
//     delete[] p;
// });
// std::weak_ptr<int> wp = sp;  // ✅ Valid, but use with care
// 🧨 Caution: This is risky — weak_ptr will point to the first element only, and .lock() returns a shared_ptr to just that one element, not the whole array.


// BEST 


// auto vec = std::make_shared<std::vector<int>>(5);
// std::weak_ptr<std::vector<int>> wp = vec;




// You can’t use custom deleters with std::make_shared() or std::make_unique() — because:

// They internally allocate memory in a single block.

// There’s no overload that takes a custom deleter.

// So if you need a custom deleter, you must use new + constructor manually:

// cpp
// Copy
// Edit
// std::shared_ptr<int> ptr(new int(42), customDeleter); // ✅ custom deleter
// std::make_shared<int>(42);                           // ❌ no way to pass custom deleter