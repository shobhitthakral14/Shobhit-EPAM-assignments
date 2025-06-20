// In C++ STL, invalidation refers to the situation where iterators, references, or pointers to elements in a container become invalid
// due to modifications in the container (like insertions, deletions, or resizing).
// Accessing an invalidated iterator or reference causes undefined behavior, making this a frequent source of bugs.


// 🔹 1. Vector (std::vector)
// | Operation        | Iterator Invalidation                                           | Reference/Pointer Invalidation |
// | ---------------- | --------------------------------------------------------------- | ------------------------------ |
// | `push_back()`    | ✅ *May invalidate* all if capacity changes                      | ✅ *May invalidate*             |
// | `emplace_back()` | Same as `push_back()`                                           | Same                           |
// | `insert()`       | ✅ *May invalidate* all from insertion point if capacity changes | ✅ Possibly all                 |
// | `erase()`        | ✅ Invalidates iterators at or after erased position             | ✅ Only erased elements         |
// | `clear()`        | ✅ All invalidated                                               | ✅ All invalidated              |
// | `resize()`       | ✅ All invalidated if reallocation occurs                        | ✅ Possibly all                 |

// 💡 If a vector reallocation happens (capacity increases), all iterators, pointers, and references become invalid.



//  2. Deque (std::deque)
// push_front(), push_back(), insert() → May invalidate all iterators, but pointers/references to elements are generally safe unless reallocation occurs.

// erase() → Invalidates iterators and references at or after the erased element.

// 🔥 deque grows at both ends, so insertions at either end may invalidate iterators differently from vector.


// 🔹 3. List (std::list) and forward_list

// | Operation  | Iterator Invalidation | Reference/Pointer Invalidation |
// | ---------- | --------------------- | ------------------------------ |
// | `insert()` | ❌ No invalidation     | ❌ None                         |
// | `erase()`  | ✅ Only erased element | ✅ Only erased element          |
// | `splice()` | ❌ No invalidation     | ❌ None                         |

// 🔹 4. Set / Map / Multiset / Multimap

// | Operation  | Iterator Invalidation  | Reference/Pointer Invalidation |
// | ---------- | ---------------------- | ------------------------------ |
// | `insert()` | ❌ No invalidation      | ❌ None                         |
// | `erase()`  | ✅ Only erased iterator | ✅ Only erased element          |


// 🔹 5. Unordered Containers
// For unordered_map, unordered_set, etc.:

// | Operation                | Iterator Invalidation                    | Reason                         |
// | ------------------------ | ---------------------------------------- | ------------------------------ |
// | `insert()`               | ✅ May invalidate all if rehashing occurs | hash table resized             |
// | `erase()`                | ✅ Only erased element                    |                                |
// | `rehash()` / `reserve()` | ✅ All iterators invalidated              | triggers internal table change |




// use .reserve for vectors to prevent invalidations  