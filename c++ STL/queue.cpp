// ✅The queue in the C++ Standard Template Library(STL) is a container adapter that works on the principle of FIFO(First - In - First - Out).

// Characteristics of Queue :
// Elements are inserted at the back(tail) and removed from the front(head).
// Works on FIFO(First - In - First - Out) principle.
// It is an adapter container, which means it uses an underlying container(like deque or list) to store the data.

// ✅Syntax :
// 	std::queue<T, Container>q;
// T: Type of the elements.
// Container : Type of the underlying container used to store data(default is std::deque<T>).

// std::queue<int> q;  // default underlying container:  std::deque<int>q;
// std::queue<int, std::list<int>>q;

// std::deque(Default) : The double - ended queue(std::deque) is the default container for std::queue.
// Because It provides efficient insertion and removal at both ends.

// ✅you cannot use std::vector as an underlying container for std::queue in C++ STL
// because std::vector does not fulfill all the necessary requirements of the underlying container expected by std::queue.
// Requirements like :
// push_back() - To add an element to the end(used in queue::push()).
// pop_front() - To remove an element from the front(used in queue::pop()).
// While std::deque provides both push_back() and pop_front(), the std::vector does not implement a pop_front() function efficiently
// because removing an element from the front of the vector requires shifting all the subsequent elements, which can be costly(O(n) in time complexity).


// ✅Function	   Description
// push()	        q.push(10); // Adds 10 to the back of the queue
// emplace()	    q.emplace(20); // Constructs 20 at the back of the queue
// pop()	        q.pop(); // Removes the front element
// front()	        cout << q.front(); // Prints the front element
// back()	        cout << q.back(); // Prints the back element
// empty()	        cout << (q.empty() ? "Empty" : "Not empty"); // Checks if queue is empty
// size()	        cout << q.size(); // Prints the size of the queue
// swap()	        q2.swap(q1); // Exchanges contents of q1 and q2


// #include <iostream>
// #include <queue>

// int main() {
//     std::queue<int> q1, q2; 

//     std::cout << "Adding elements to q1 using push():\n";
//     q1.push(10);
//     q1.push(20);
//     q1.push(30);
//     std::cout << "q1 size after push: " << q1.size() << "\n";


//     std::cout << "\nAdding an element to q1 using emplace():\n";
//     q1.emplace(40);
//     std::cout << "q1 size after emplace: " << q1.size() << "\n";
//     std::cout << "Back element after emplace: " << q1.back() << "\n";

 
//     std::cout << "\nThe front element of q1 is: " << q1.front() << "\n";
//     std::cout << "The back element of q1 is: " << q1.back() << "\n";

   
//     std::cout << "\nRemoving the front element of q1 using pop():\n";
//     q1.pop();
//     std::cout << "The front element after pop: " << q1.front() << "\n";
//     std::cout << "q1 size after pop: " << q1.size() << "\n";

    

//     std::cout << (q1.empty() ? "q1 is empty" : "q1 is not empty") << "\n";

//     // Adding elements to q2
 
//     q2.push(100);
//     q2.push(200);
//     q2.push(300);
//     std::cout << "q2 size: " << q2.size() << "\n";

 
//     q1.swap(q2);

//     std::cout << "\nAfter swap:\n";
//     std::cout << "q1 size: " << q1.size() << "\n";
//     std::cout << "q2 size: " << q2.size() << "\n";

//     return 0;
// }



// ✅Use Cases of Queue :
// 1.Task Scheduling(CPU or OS) :
// 	In an operating system, tasks are scheduled based on their arrival time(FIFO) or priority.

// 	2.Printing Jobs(Print Spooler) :
// 	Printers queue incoming print jobs so that documents are printed in the order they were received.

// 	3.Customer Service / Call Center Systems :
// Customer requests are handled in the order they are received, whether via phone calls or chat.

// 4.Waiting Lines(Queues in Real Life) :
// 	Scenario : People lining up in a supermarket or at a bank for service form a queue

// 	5.Breadth - First Search(BFS) in Graphs or Trees :
// 	Queue is used for exploring nodes level by level in problems like shortest path, social network connections, etc.

// 	6.Job / Resource Allocation in Multi - Threaded Applications :
// Workers or threads in an application take tasks from a queue to execute them sequentially.




