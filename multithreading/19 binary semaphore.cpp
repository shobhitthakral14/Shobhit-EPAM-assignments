/*===== binary semaphore =====*/
//debug code in c++ 20 environment.

// semaphores are used for signaling purposes.
// mutex are used for ownership purpose only.
// bs.acquire() the lock and bs.release() the lock; 

//#include <chrono>
//#include <iostream>
//#include <semaphore>
//#include <thread>
//using namespace std;

// global binary semaphore instances
// object counts are set to zero
// objects are in non-signaled state

//std::binary_semaphore                 //defined in c++20
//   smphSignalMainToThread{ 0 },
//   smphSignalThreadToMain{ 0 };
//
//void ThreadProc()
//{
//    // wait for a signal from the main proc
//    // by attempting to decrement the semaphore
//    smphSignalMainToThread.acquire();
//
//    // this call blocks until the semaphore's count
//    // is increased from the main proc
//    std::cout << "[thread] Got the signal\n"; // response message
//
//    using namespace std::literals;
//    std::this_thread::sleep_for(3s);
//
//    std::cout << "[thread] Send the signal\n"; // message
//
//    // signal the main proc back
//    smphSignalThreadToMain.release();
//}
//
//int main()
//{
//    // create some worker thread
//    std::thread thrWorker(ThreadProc);
//
//    std::cout << "[main] Send the signal\n"; // message
//
//    // signal the worker thread to start working
//    // by increasing the semaphore's count
//    smphSignalMainToThread.release();
//
//    // wait until the worker thread is done doing the work
//    // by attempting to decrement the semaphore's count
//    smphSignalThreadToMain.acquire();
//
//    std::cout << "[main] Got the signal\n"; // response message
//    thrWorker.join();
//}






// MUTEX                                SEMAPHORES
                                        // came in cpp 20
// mutex.lock();
// mutex.unlock();

// mutex is a locking 
// semaphore is a signaling mechanism 





//Counting Semaphore: Allows N threads to access a resource simultaneously (used for limiting access to a pool of resources).

// Binary Semaphore (a.k.a. Mutex): Can have only 0 or 1 as value.