// auto_ptr is a smart pointer in C++ that was introduced in C++98 to handle dynamic memory management automatically. It belongs to the <memory> header.
// However, it is deprecated in C++11 and removed in C++17, and replaced with unique_ptr due to various serious issues (especially related to copy semantics).

// auto_ptr is a smart pointer that owns and manages another object through a pointer and disposes of that object when the auto_ptr goes out of scope.

// #include <memory>
// using namespace std;

// int main() {
//     auto_ptr<int> p1(new int(10));
//     cout << *p1 << endl;
// }


// | Property                    | Description                                                                   |
// | --------------------------- | ----------------------------------------------------------------------------- |
// | **Ownership transfer**      | Copying an `auto_ptr` transfers ownership. The original pointer becomes null. |
// | **Single-owner model**      | Only one `auto_ptr` can own a pointer at a time.                              |
// | **Automatic destruction**   | Deletes the object it holds when it goes out of scope.                        |
// | **Copyable**                | Unlike `unique_ptr`, it allows copy — but transfers ownership on copy.        |
// | **Not safe for containers** | Can't be used safely in STL containers (like `vector<auto_ptr<T>>`).          |


// #include <iostream>
// #include <memory>
// using namespace std;

// int main() {
//     auto_ptr<int> p1(new int(100));
//     auto_ptr<int> p2 = p1; // Ownership transferred
//     cout << *p2 << endl;

//     if (p1.get() == nullptr) {
//         cout << "p1 is now null" << endl;
//     }
// }
