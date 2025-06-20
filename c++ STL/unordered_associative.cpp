//The C++ Standard Template Library(STL) provides unordered associative containers like std::unordered_set, std::unordered_map, 
//std::unordered_multiset, and std::unordered_multimap.These containers are implemented using hash tables, which allow for average
//O(1) time complexity for insertion, deletion, and search operations.Unlike their ordered counterparts(std::set, std::map, etc.),
//unordered containers do not maintain elements in sorted order.


//1. std::unordered_set
//A std::unordered_set is an associative container that stores unique elements in an unordered manner.
//
//Key Features :
//Unique Elements : A std::unordered_set does not allow duplicate elements.
//Unordered : Elements are stored in no particular order.
//Fast Operations : Average O(1) time complexity for insertion, deletion, and search(worst - case O(n) due to hash collisions).
//Hashing : Uses a hash function to determine the position of elements in the hash table.
//
//#include <iostream>
//#include <unordered_set>
//
//int main() {
//    std::unordered_set<int> us;
//
//    // Insert elements
//    us.insert(10);
//    us.insert(20);
//    us.insert(10); // Duplicate, will be ignored
//
//    // Access elements
//    for (int x : us) {
//        std::cout << x << " "; // Output: 10 20 (order may vary)
//    }
//
//    // Check if an element exists
//    if (us.find(20) != us.end()) {
//        std::cout << "\n20 is in the unordered set";
//    }
//
//    // Erase an element
//    us.erase(10);
//
//    // Size of the unordered set
//    std::cout << "\nSize: " << us.size(); // Output: 1
//
//    return 0;
//}




//2. std::unordered_map
//A std::unordered_map is an associative container that stores key - value pairs in an unordered manner.
//
//Key Features :
//Unique Keys : Each key in a std::unordered_map is unique.
//Unordered : Keys are stored in no particular order.
//Fast Operations : Average O(1) time complexity for insertion, deletion, and search(worst - case O(n) due to hash collisions).
//Key - Value Pair : Each element is a pair of a key and a value(std::pair<Key, Value>).
//Hashing : Uses a hash function to determine the position of keys in the hash table.
//
//
//#include <iostream>
//#include <unordered_map>
//
//int main() {
//    std::unordered_map<int, std::string> um;
//
//    // Insert elements
//    um[1] = "one";
//    um[2] = "two";
//    um[3] = "three";
//
//    // Access elements
//    std::cout << um[2]; // Output: two
//
//    // Iterate over the unordered map
//    for (const auto& pair : um) {
//        std::cout << pair.first << ": " << pair.second << "\n";
//    }
//
//    // Check if a key exists
//    if (um.find(2) != um.end()) {
//        std::cout << "Key 2 exists";
//    }
//
//    // Erase an element by key
//    um.erase(2);
//
//    // Size of the unordered map
//    std::cout << "\nSize: " << um.size(); // Output: 2
//
//    return 0;
//}



//3. std::unordered_multiset
//A std::unordered_multiset is similar to std::unordered_set, but it allows duplicate elements.
//
//Key Features :
//Duplicate Elements : A std::unordered_multiset can store multiple elements with the same value.
//Unordered : Elements are stored in no particular order.
//Fast Operations : Average O(1) time complexity for insertion, deletion, and search(worst - case O(n) due to hash collisions).
//Hashing : Uses a hash function to determine the position of elements in the hash table.
//
//
//#include <iostream>
//#include <unordered_set>
//
//int main() {
//    std::unordered_multiset<int> ums;
//
//    // Insert elements
//    ums.insert(10);
//    ums.insert(20);
//    ums.insert(10); // Duplicate, allowed in multiset
//
//    // Access elements
//    for (int x : ums) {
//        std::cout << x << " "; // Output: 10 10 20 (order may vary)
//    }
//
//    // Count occurrences of an element
//    std::cout << "\nCount of 10: " << ums.count(10); // Output: 2
//
//    // Erase all occurrences of an element
//    ums.erase(10);
//
//    // Size of the unordered multiset
//    std::cout << "\nSize: " << ums.size(); // Output: 1
//
//    return 0;
//}





//4. std::unordered_multimap
//A std::unordered_multimap is similar to std::unordered_map, but it allows duplicate keys.
//
//Key Features :
//Duplicate Keys : A std::unordered_multimap can store multiple elements with the same key.
//Unordered : Keys are stored in no particular order.
//Fast Operations : Average O(1) time complexity for insertion, deletion, and search(worst - case O(n) due to hash collisions).
//Key - Value Pair : Each element is a pair of a key and a value(std::pair<Key, Value>).
//Hashing : Uses a hash function to determine the position of keys in the hash table.
//
//
//#include <iostream>
//#include <unordered_map>
//
//int main() {
//    std::unordered_multimap<int, std::string> umm;
//
//    // Insert elements
//    umm.insert({ 1, "one" });
//    umm.insert({ 2, "two" });
//    umm.insert({ 1, "uno" }); // Duplicate key allowed
//
//    // Access elements
//    for (const auto& pair : umm) {
//        std::cout << pair.first << ": " << pair.second << "\n";
//    }
//
//    // Find all elements with a specific key
//    auto range = umm.equal_range(1);
//    for (auto it = range.first; it != range.second; ++it) {
//        std::cout << it->first << ": " << it->second << "\n";
//    }
//
//    // Erase all elements with a specific key
//    umm.erase(1);
//
//    // Size of the unordered multimap
//    std::cout << "\nSize: " << umm.size(); // Output: 1
//
//    return 0;
//}                