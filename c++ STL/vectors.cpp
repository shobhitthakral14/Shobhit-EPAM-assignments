//std::vector:

// A dynamic array that can grow or shrink in size.    
//Provides fast random access(O(1)) and efficient insertion / removal at the end(O(1)).
//Insertion / removal in the middle or beginning is slower(O(n)).
//contigous memory like array 
//If capacity is exceeded during push_back, vector doubles its capacity (usually).
// This involves allocating new memory and moving/copying elements (expensive operation).


// It reallocates a larger memory block (usually double the size), copies/moves existing elements to the new block, 
//then adds the new element. Old memory is released.





//Declaration Examples :
//std::vector<int> vec1;                // Empty vector of integers
//std::vector<int> vec2(5);             // Vector of size 5, all elements initialized to 0
//std::vector<int> vec3(5, 10);         // Vector of size 5, all elements initialized to 10
//std::vector<int> vec4 = { 1, 2, 3, 4 }; // Vector initialized with a list of values


//Common Operations on Vectors
//
//1. Adding Elements
//Use push_back() to add an element to the end of the vector.
//Use emplace_back() to construct an element in-place at the end of the vector(more efficient for complex objects).
//
//std::vector<int> vec;
//vec.push_back(10);  // Add 10 to the end
//vec.push_back(20);  // Add 20 to the end
//vec.emplace_back(30); // Add 30 to the end (in-place construction)



//2. Accessing Elements
//Use the[] operator or the at() method to access elements by index.
//Use front() and back() to access the first and last elements.

//std::vector<int> vec = { 10, 20, 30 };
//std::cout << vec[1];       // Output: 20
//std::cout << vec.at(2);    // Output: 30
//std::cout << vec.front();  // Output: 10
//std::cout << vec.back();   // Output: 30

//3. Removing Elements
//Use pop_back() to remove the last element.
//Use erase() to remove an element at a specific position or a range of elements.
//Use clear() to remove all elements.
//
//std::vector<int> vec = { 10, 20, 30, 40 };
//vec.pop_back();            // Removes 40
//vec.erase(vec.begin() + 1); // Removes the element at index 1 (20)
//vec.clear();               // Removes all elements

//4. Inserting Elements
//Use insert() to insert an element at a specific position.
//
//std::vector<int> vec = { 10, 20, 30 };
//vec.insert(vec.begin() + 1, 15); // Inserts 15 at index 1

//5. Resizing and Capacity
//Use resize() to change the size of the vector.
//Use reserve() to pre - allocate memory for a specific number of elements(to avoid frequent reallocations).
//Use shrink_to_fit() to reduce the capacity to match the current size.
//std::vector<int> vec = { 10, 20, 30 };
//vec.resize(5);             // Resizes to 5 elements (new elements initialized to 0)
//vec.reserve(10);           // Reserves space for 10 elements
//vec.shrink_to_fit();       // Reduces capacity to match the current size

//6. Iterating Over a Vector
//Use a for loop, range - based for loop, or iterators to traverse the vector.
//
//std::vector<int> vec = { 10, 20, 30 };
//
//// Using a traditional for loop
//for (int i = 0; i < vec.size(); ++i) {
//    std::cout << vec[i] << " ";
//}
//
//// Using a range-based for loop
//for (int val : vec) {
//    std::cout << val << " ";
//}
//
//// Using iterators
//for (auto it = vec.begin(); it != vec.end(); ++it) {
//    std::cout << *it << " ";
//}


//Capacity Functions
//Vectors provide several functions to query their size and capacity:
//size() : Returns the number of elements in the vector.
//capacity() : Returns the total capacity of the vector(the amount of memory allocated).
//empty() : Returns true if the vector is empty, otherwise false.
//max_size() : Returns the maximum number of elements the vector can hold.
//
//std::vector<int> vec = { 10, 20, 30 };
//std::cout << vec.size();     // Output: 3
//std::cout << vec.capacity(); // Output: 4 (or more, depending on implementation)
//std::cout << vec.empty();    // Output: 0 (false)


#include <iostream>
#include <vector>

int main() {
    // Create a vector and add elements
    std::vector<int> vec = { 10, 20, 30 };
    vec.push_back(40);
    vec.push_back(50);

    // Access elements
    std::cout << "Elements: ";
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Remove an element
    vec.pop_back();

    // Insert an element
    vec.insert(vec.begin() + 1, 15);

    // Display size and capacity
    std::cout << "Size: " << vec.size() << std::endl;
    std::cout << "Capacity: " << vec.capacity() << std::endl;

    // Iterate using iterators
    std::cout << "Using iterators: ";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}


//Advantages of std::vector
// Dynamic Resizing : Automatically grows or shrinks as needed.
// Random Access : Provides fast access to elements using an index.
// Rich Functionality : Offers a wide range of member functions for manipulation.
// Memory Management : Handles memory allocation and deallocation automatically.

//Disadvantages of std::vector
//Insertion / Deletion Overhead :
//Inserting or deleting elements in the middle or beginning of the vector is slow(O(n)) because elements need to be shifted.
//Memory Reallocation :
//When the vector grows beyond its capacity, reallocation can be expensive as it involves copying all elements to a new memory location.



// size() = actual number of elements.

// capacity() = allocated space (≥ size).




// v.erase(std::remove_if(v.begin(), v.end(), [](int x){ return x % 2 == 0; }), v.end());