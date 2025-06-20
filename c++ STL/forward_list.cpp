// std::forward_list is a container introduced in C++11 that implements a singly linked list. Unlike std::list, which is a doubly linked list, a forward_list supports only forward traversal (hence the name).

// Key Properties:
// Singly linked list.

// Lower overhead than std::list (no back pointers).

// Fast insertions/removals at the front (O(1)).

// No size() member function (you have to compute it manually).

// More memory-efficient than std::list.

// #include <iostream>
// #include <forward_list>
// using namespace std;

// int main() {
//     forward_list<int> fl = {1, 2, 3};

//     // Insert at front
//     fl.push_front(0); // {0, 1, 2, 3}

//     // Insert after a specific position
//     auto it = fl.begin();
//     fl.insert_after(it, 10); // {0, 10, 1, 2, 3}

//     // Erase after
//     fl.erase_after(it); // removes 10

//     // Traversal
//     for (int val : fl) {
//         cout << val << " ";
//     }
// }


// | Function                 | Description                                        |
// | ------------------------ | -------------------------------------------------- |
// | `push_front(val)`        | Insert at the beginning                            |
// | `pop_front()`            | Remove first element                               |
// | `insert_after(pos, val)` | Insert after a position                            |
// | `erase_after(pos)`       | Erase after a position                             |
// | `before_begin()`         | Iterator before first element (for `insert_after`) |
// | `remove(val)`            | Removes all elements equal to val                  |
// | `sort()`                 | Sorts the list                                     |
// | `merge()`                | Merges two sorted forward\_lists                   |
// | `unique()`               | Removes consecutive duplicates                     |
// | `reverse()`              | Reverses the list                                  |


// Why No size()?
// Because it’s a singly linked list, size calculation would require traversal (O(n)), and STL doesn't store the size explicitly in forward_list to keep it lightweight.



// | Operation                            | Time Complexity    |
// | ------------------------------------ | ------------------ |
// | `push_front`, `pop_front`            | O(1)               |
// | `insert_after`, `erase_after`        | O(1)               |
// | `sort`, `merge`, `unique`, `reverse` | O(n log n) or O(n) |
// | Traversal                            | O(n)               |
// | Random Access                        | ❌ Not allowed      |
