//std::list is a container in the C++ Standard Template Library(STL) that implements a doubly linked list.Unlike std::vector, 
//which uses a contiguous memory layout, std::list stores its elements in non - contiguous memory, with each element containing
//pointers to the previous and next elements.This structure makes std::list particularly efficient for certain operations, such 
//as frequent insertions and deletions.


//Doubly Linked List :
//Each element in the list contains a pointer to the previous and next elements.
//This allows bidirectional traversal of the list.

//Efficient Insertions and Deletions :
//Insertion and deletion of elements at any position(beginning, middle, or end) are efficient(O(1)) if you already have an iterator pointing to the position.
//Unlike std::vector, no shifting of elements is required.

//No Random Access :
//Unlike std::vector, std::list does not support random access to elements using an index(e.g., list[i] is not allowed).
//Traversal is sequential, which can be slower for accessing elements.

//Dynamic Size :
//The size of the list can grow or shrink dynamically during runtime.

//Iterators :
//std::list provides bidirectional iterators, allowing traversal in both forward and backward directions.

//Memory Overhead :
//Each element in the list requires extra memory for the pointers to the previous and next elements, making it less memory - efficient compared to std::vector.

//#include<list>
//std::list<int> lst1;                // Empty list of integers
//std::list<int> lst2(5);             // List of size 5, all elements initialized to 0
//std::list<int> lst3(5, 10);         // List of size 5, all elements initialized to 10
//std::list<int> lst4 = { 1, 2, 3, 4 }; // List initialized with a list of values


//Common Operations on list


//1. Adding Elements
//Use push_back() to add an element to the end of the list.
//Use push_front() to add an element to the beginning of the list.
//Use emplace_back() and emplace_front() for in - place construction of elements.
//std::list<int> lst;

//lst.push_back(10);   // Add 10 to the end
//lst.push_front(5);   // Add 5 to the beginning
//lst.emplace_back(15); // Add 15 to the end (in-place construction)
//lst.emplace_front(2); // Add 2 to the beginning (in-place construction)


//2. Removing Elements
//Use pop_back() to remove the last element.
//Use pop_front() to remove the first element.
//Use erase() to remove an element at a specific position or a range of elements.
//Use remove() to remove all occurrences of a specific value.
//Use clear() to remove all elements.
//
//std::list<int> lst = { 10, 20, 30, 40 };
//lst.pop_back();             // Removes 40
//lst.pop_front();            // Removes 10
//lst.remove(20);             // Removes all occurrences of 20
//lst.clear();                // Removes all elements


//3. Inserting Elements
//Use insert() to insert an element at a specific position.
//Use emplace() to construct an element in - place at a specific position.

//std::list<int> lst = { 10, 20, 30 };
//auto it = lst.begin();
//std::advance(it, 1);        // Move iterator to the second position
//lst.insert(it, 15);         // Inserts 15 at the second position
//lst.emplace(it, 12);        // Constructs 12 in-place at the second position


//4. Accessing Elements
//Use front() to access the first element.
//Use back() to access the last element.
//Note: Random access using an index(e.g., lst[i]) is not supported.
//
//std::list<int> lst = { 10, 20, 30 };
//std::cout << lst.front();   // Output: 10
//std::cout << lst.back();    // Output: 30


//5. Iterating Over a List
//Use a range - based for loop or iterators to traverse the list.

//std::list<int> lst = { 10, 20, 30 };

//// Using a range-based for loop
//for (int val : lst) {
//    std::cout << val << " ";
//}
//
//// Using iterators
//for (auto it = lst.begin(); it != lst.end(); ++it) {
//    std::cout << *it << " ";
//}


//6. Merging and Splicing
//Use merge() to merge two sorted lists.
//Use splice() to transfer elements from one list to another.

//std::list<int> lst1 = { 10, 20, 30 };
//std::list<int> lst2 = { 15, 25 };
//lst1.merge(lst2);           // Merges lst2 into lst1 (both must be sorted)
//
//std::list<int> lst3 = { 40, 50 };
//lst1.splice(lst1.end(), lst3); // Transfers all elements of lst3 to the end of lst1


//Capacity Functions
//std::list provides functions to query its size and check if it is empty :
//
//size() : Returns the number of elements in the list.
//empty() : Returns true if the list is empty, otherwise false.
//max_size() : Returns the maximum number of elements the list can hold.



#include <iostream>
#include <list>

int main() {
    // Create a list and add elements
    std::list<int> lst = { 10, 20, 30 };
    lst.push_back(40);
    lst.push_front(5);

    // Display elements
    std::cout << "List elements: ";
    for (int val : lst) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Remove an element
    lst.pop_back();

    // Insert an element
    auto it = lst.begin();
    std::advance(it, 2); // Move iterator to the third position
    lst.insert(it, 25);

    // Sort and reverse the list
    lst.sort();
    lst.reverse();

    // Display the modified list
    std::cout << "Modified list: ";
    for (int val : lst) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}



//Advantages of std::list

//Efficient Insertions and Deletions:
//Insertion and deletion at any position are efficient(O(1)) if you have an iterator pointing to the position.
//No need to shift elements as in std::vector.

//Dynamic Size :
//The size of the list can grow or shrink dynamically during runtime.

//Bidirectional Traversal :
//Supports bidirectional traversal using iterators.

//Specialized Operations :
//Provides unique operations like splice(), merge(), sort(), and reverse().

//Disadvantages of std::list

//No Random Access :
//Accessing elements by index is not supported, and traversal is sequential, which can be slower compared to std::vector.

//Memory Overhead :
//Each element requires extra memory for the pointers to the previous and next elements, making it less memory - efficient than std::vector.

//Cache Unfriendliness :
//Since elements are stored in non - contiguous memory, accessing elements is slower due to poor cache locality.
