
//The C++ Standard Template Library(STL) provides associative containers like std::set, std::map, std::multiset, 
//and std::multimap.These containers are designed to store elements in a way that allows for fast retrieval, insertion,
//and deletion.They are implemented as balanced binary search trees(usually Red - Black Trees), which ensures that operations 
//like insertion, deletion, and search have a time complexity of O(log n).

//1. std::set
//A std::set is an associative container that stores unique elements in a sorted order.
//
//Key Features :
//Unique Elements : A std::set does not allow duplicate elements.
//Sorted Order : Elements are automatically sorted in ascending order(by default) or by a custom comparator.
//Fast Operations : Insertion, deletion, and search operations are O(log n).
//No Direct Access by Index : You cannot access elements using an index(e.g., set[i] is not allowed).

// #include <iostream>
// #include <set>

// int main() {
//     std::set<A> s;

//     // Insert elements
//     s.insert(10);
//     s.insert(20);
//     s.insert(10); // Duplicate, will be ignored

//     // Access elements
//     for (int x : s) {
//         std::cout << x << " "; // Output: 10 20
//     }

//     // Check if an element exists
//     if (s.find(20) != s.end()) {
//         std::cout << "\n20 is in the set";
//     }

//     // Erase an element
//     s.erase(10);

//     // Size of the set
//     std::cout << "\nSize: " << s.size(); // Output: 1

//     return 0;
// }




//2. std::map
//A std::map is an associative container that stores key - value pairs in a sorted order by key.
//
//Key Features :
//Unique Keys : Each key in a std::map is unique.
//Sorted by Key : Keys are automatically sorted in ascending order(by default) or by a custom comparator.
//Fast Operations : Insertion, deletion, and search operations are O(log n).
//Key - Value Pair : Each element is a pair of a key and a value(std::pair<Key, Value>).


//#include <iostream>
//#include <map>
//
//int main() {
//    std::map<int, std::string> m;
//
//    // Insert elements
//    m[1] = "one";
//    m[2] = "two";
//    m[3] = "three";
//
//    // Access elements
//    std::cout << m[2] << std::endl; // Output: two
//
//    // Iterate over the map
//    for (const auto& pair : m) {
//        std::cout << pair.first << ": " << pair.second << "\n";
//    }
//
//    // Check if a key exists
//    if (m.find(2) != m.end()) {
//        std::cout << "Key 2 exists";
//    }
//
//    // Erase an element by key
//    m.erase(2);
//
//    // Size of the map
//    std::cout << "\nSize: " << m.size(); // Output: 2
//
//    return 0;
//}




//3. std::multiset
//A std::multiset is similar to std::set, but it allows duplicate elements.
//
//Key Features :
//Duplicate Elements : A std::multiset can store multiple elements with the same value.
//Sorted Order : Elements are automatically sorted in ascending order(by default) or by a custom comparator.
//Fast Operations : Insertion, deletion, and search operations are O(log n).

//#include <iostream>
//#include <set>
//
//int main() {
//    std::multiset<int> ms;
//
//    // Insert elements
//    ms.insert(10);
//    ms.insert(20);
//    ms.insert(10); // Duplicate, allowed in multiset
//
//    // Access elements
//    for (int x : ms) {
//        std::cout << x << " "; // Output: 10 10 20
//    }
//
//    // Count occurrences of an element
//    std::cout << "\nCount of 10: " << ms.count(10); // Output: 2
//
//    // Erase all occurrences of an element
//    ms.erase(10);
//
//    // Size of the multiset
//    std::cout << "\nSize: " << ms.size(); // Output: 1
//
//    return 0;
//}



//4. std::multimap
//A std::multimap is similar to std::map, but it allows duplicate keys.
//
//Key Features :
//Duplicate Keys : A std::multimap can store multiple elements with the same key.
//Sorted by Key : Keys are automatically sorted in ascending order(by default) or by a custom comparator.
//Fast Operations : Insertion, deletion, and search operations are O(log n).
//Key - Value Pair : Each element is a pair of a key and a value(std::pair<Key, Value>).


//#include <iostream>
//#include <map>
//
//int main() {
//    std::multimap<int, std::string> mm;
//
//    // Insert elements
//    mm.insert({ 1, "one" });
//    mm.insert({ 2, "two" });
//    mm.insert({ 1, "uno" }); // Duplicate key allowed
//
//    // Access elements
//    for (const auto& pair : mm) {
//        std::cout << pair.first << ": " << pair.second << "\n";
//    }
//
//    // Find all elements with a specific key
//    auto range = mm.equal_range(1);
//    for (auto it = range.first; it != range.second; ++it) {
//        std::cout << it->first << ": " << it->second << "\n";
//    }
//
//    // Erase all elements with a specific key
//    mm.erase(1);
//
//    // Size of the multimap
//    std::cout << "\nSize: " << mm.size(); // Output: 1
//
//    return 0;
//}