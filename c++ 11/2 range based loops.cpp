// Range-based loops in C++ are a modern and elegant way to iterate over elements of a container (like arrays, vectors, maps, etc.). 
// Introduced in C++11, they simplify the syntax and reduce the risk of common iteration errors.

// for (declaration : container) {
//     // use declaration
// }


// std::vector<int> nums = {1, 2, 3, 4};
// for (int num : nums) {
//     std::cout << num << " ";
// }


// for (auto x : container)	Iterates with a copy (modifying doesn't affect original)
// for (auto& x : container)	Iterates with reference (modifying affects original)
// for (const auto& x : container)	Read-only iteration, avoids unnecessary copying

// for (auto x : container)  ==
// for (auto it = container.begin(); it != container.end(); ++it) {
//     auto x = *it;
// }



// if we use auto without reference &
// You get a copy, so changes won't reflect back.

// working with containers
// std::map<int, std::string> m = {{1, "a"}, {2, "b"}};
// for (const auto& p : m) {
//     std::cout << p.first << " => " << p.second << "\n";
// }



//auto&& enables perfect forwarding:

// Works for both lvalues and rvalues

// Rare in range-based loops but safe for generic code



//Avoid modifying the container structure (e.g., inserting or erasing elements) inside a range-based loop—it leads to undefined behavior in most STL containers.


//you cannot use a range-based for loop on a type that does not provide begin() and end() methods (or free functions begin(obj) and end(obj)).


//Range-based for loops rely on iterators obtained at the start (begin() and end()).
// Modifying container structure may invalidate iterators.
// The loop will continue to use invalidated iterators, causing crashes or unexpected results.


// Using a temporary object directly in a range-based for loop can cause dangling reference issues or undefined behavior if you’re not careful.


// std::vector<int> createVec() {
//     return {1, 2, 3};
// }

// for (auto& x : createVec()) {  // x is a reference to temporary vector's elements
//     std::cout << x << " ";     // Undefined behavior: temporary destroyed immediately
// }


// how to prevent 

// for (auto x : createVec()) {
//     std::cout << x << " ";  // safe, x is a copy
// }

// or 

// const auto& vec = createVec();  // lifetime extended here
// for (auto& x : vec) {
//     std::cout << x << " ";  // safe
// }



// C++ 17 concept 

// std::map<int, std::string> m = {{1, "a"}, {2, "b"}};
// for (const auto& [key, value] : m) {
//     std::cout << key << " -> " << value << "\n";
// }
