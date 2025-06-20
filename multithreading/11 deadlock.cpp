//In C++, deadlock occurs when multiple threads are unable to proceed because they are waiting for locks or shared resources held by one another.
// Deadlock in C++ often arises when using synchronization tools such as std::mutex or std::lock_guard from the <thread> and <mutex> libraries.


// EXAMPLE OF DEADLOCK 

#include<iostream>
#include<thread>
#include<mutex>

std::mutex m1;
std::mutex m2;

void thread1(){
	m1.lock();
	// std::this_thread::sleep_for(std::chrono::seconds(1));
	m2.lock();
	std::cout << "critical section of thread one" << std::endl;
	m1.unlock();
	m2.unlock();
}

void thread2() {
	m2.lock();
	// std::this_thread::sleep_for(std::chrono::seconds(1));
	m1.lock();
	std::cout << "critical section of thread two" << std::endl;
	m2.unlock();
	m1.unlock();
}

int main() {
	std::thread t1(thread1);              // here thread1 is trying to lock mutex m1 and then m2
	std::thread t2(thread2);              // here thread2 is trying to lock mutex m2 and then m1
	t1.join();
	t2.join();
	return 0;
}


// THIS IS BASICALLY A DEADLOCK SITUATION 

// THERE IS A POSSIBILITY THAT THIS WILL NOT GIVE ERROR AS out system is very fast that there might be possibility that thread2 will not be started by the time thread1 end







// IT CAN BE USED SOLVED USING 

//1.) LOCK OREDERING 

// MAKING THE ORDER OF THE LOCK SAME IN BOTH THE FUNCTIONS SO THTA BOTH THE MUTEXES ARE LOCKED AND UNLOCKED AT THE SAME TIME WHICH WILL NOT GIVE ERROR 



//2.) USING TRY_LOCK 

// #include <iostream>
// #include <thread>
// #include <mutex>

// std::mutex mutex1;
// std::mutex mutex2;

// void threadA() {
//     while (true) {
//         if (mutex1.try_lock()) {
//             std::cout << "Thread A acquired mutex1\n";
//             std::this_thread::sleep_for(std::chrono::milliseconds(100)); // simulate work

//             if (mutex2.try_lock()) {
//                 std::cout << "Thread A acquired mutex2\n";
//                 mutex2.unlock();
//                 mutex1.unlock();
//                 break;
//             } else {
//                 std::cout << "Thread A failed to acquire mutex2\n";
//                 mutex1.unlock();
//                 std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Retry
//             }
//         } else {
//             std::cout << "Thread A failed to acquire mutex1\n";
//             std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Retry
//         }
//     }
// }

// void threadB() {
//     while (true) {
//         if (mutex2.try_lock()) {
//             std::cout << "Thread B acquired mutex2\n";
//             std::this_thread::sleep_for(std::chrono::milliseconds(100)); // simulate work

//             if (mutex1.try_lock()) {
//                 std::cout << "Thread B acquired mutex1\n";
//                 mutex1.unlock();
//                 mutex2.unlock();
//                 break;
//             } else {
//                 std::cout << "Thread B failed to acquire mutex1\n";
//                 mutex2.unlock();
//                 std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Retry
//             }
//         } else {
//             std::cout << "Thread B failed to acquire mutex2\n";
//             std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Retry
//         }
//     }
// }

// int main() {
//     std::thread t1(threadA);
//     std::thread t2(threadB);

//     t1.join();
//     t2.join();

//     return 0;
// }






//3.) USING SCOPED LOCKS 

// std::scoped_lock automatically locks multiple mutexes in a safe, ordered way to prevent deadlocks.   IT IS OF CPP17


// #include <iostream>
// #include <thread>
// #include <mutex>

// std::mutex mutex1;
// std::mutex mutex2;

// void threadA() {
//     std::scoped_lock lock(mutex1, mutex2);  // Scoped lock avoids deadlock
//     std::cout << "Thread A has acquired both mutex1 and mutex2\n";
// }

// void threadB() {
//     std::scoped_lock lock(mutex1, mutex2);  // Scoped lock avoids deadlock
//     std::cout << "Thread B has acquired both mutex1 and mutex2\n";
// }

// int main() {
//     std::thread t1(threadA);
//     std::thread t2(threadB);

//     t1.join();
//     t2.join();

//     return 0;
// }






// ANOTHER EXAMPLE OF DEADLOCK



//Thread t1 locks the mutex and immediately returns due to return 1;.
//The unlock is never called, which means mutex m remains permanently locked.
//When t2 tries to acquire the same mutex but waits forever(deadlock/infinite block).
//Since t2.join() never finishes(because t2 is blocked on m.lock()), the program hangs or might abort depending on the system.
#include <iostream>
#include<mutex>
#include<thread>
std::mutex m;
int fun() {
   m.lock();
   return 1;        // here it is returning 
   m.unlock();
}
int main() {
   std::thread t1(fun);
   std::thread t2(fun);
   t1.join();
   t2.join();
   return 0;
}
