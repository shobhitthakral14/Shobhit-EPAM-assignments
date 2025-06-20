// In C++ STL, iterators are objects used to point to elements in containers (like vectors, lists, maps, etc.). 
//Think of them like pointers, but more abstract—they allow traversal of container elements without knowing the underlying structure.

// type of iterators
// | Type                   | Can Read | Can Write | Move Forward | Move Backward | Random Access |
// | ---------------------- | -------- | --------- | ------------ | ------------- | ------------- |
// | Input Iterator         | ✅        | ❌         | ✅            | ❌             | ❌             |
// | Output Iterator        | ❌        | ✅         | ✅            | ❌             | ❌             |
// | Forward Iterator       | ✅        | ✅         | ✅            | ❌             | ❌             |
// | Bidirectional Iterator | ✅        | ✅         | ✅            | ✅             | ❌             |
// | Random Access Iterator | ✅        | ✅         | ✅            | ✅             | ✅             |



// | Container                        | Iterator Type                                 |
// | -------------------------------- | --------------------------------------------- |
// | `vector`, `deque`                | Random Access                                 |
// | `list`                           | Bidirectional                                 |
// | `set`, `map`                     | Bidirectional                                 |
// | `unordered_set`, `unordered_map` | Forward                                       |
// | `stack`, `queue`                 | No iterators (only access via top/front/back) |


// | Function             | Meaning                                   |
// | -------------------- | ----------------------------------------- |
// | `begin()`            | Returns iterator to first element         |
// | `end()`              | Returns iterator to one past last element |
// | `rbegin()`           | Reverse begin                             |
// | `rend()`             | Reverse end                               |
// | `cbegin()`, `cend()` | Constant iterators (read-only)            |
// | `advance(it, n)`     | Moves iterator `n` steps forward/backward |
// | `next(it, n)`        | Returns new iterator `n` steps ahead      |
// | `prev(it, n)`        | Returns new iterator `n` steps back       |



#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

int main() {
    std::vector<int> v = {10, 20, 30, 40};

    // Using iterator to print values
    // std::vector<int>::iterator it;
    for(auto it = v.begin(); it != v.end(); ++it)
       { *it=*it*2;
        std::cout << *it << " ";}
    
    
    std::cout << "\nUsing reverse_iterator:\n";
    
    // std::vector<int>:: reverse_iterator rit;
    for(auto rit = v.rbegin(); rit != v.rend(); ++rit)
        std::cout << *rit << " ";
}



// time complexity of advance(it,n)
// Depends on iterator type:

// Random Access: O(1)

// Bidirectional/Forward: O(n)



//std::sort requires random access iterators. std::list provides only bidirectional ones. Use list.sort() instead.