//In this we will learn about how std::promise and std::future and how they work together to synchronise threads.
//Basically std::promise is sent to the called thread and once the value is ready we set that value in promise object,
// now at calling thread side we get that value using std::future object which was created using std::promise object before sending it to the called thread.
// And this is how we receive value from one thread to another in synchronisation.
// And we will get the value in the future object that we have created using promise object by using future.get().



//TOPIC :
//1. std::Promise
//a. used to set values and exceptions
//
//2. std::future
//a. used to get value from promise
//b. ask promise if the value is available
//c. wait for the promise

// they both are available in <future> header file 

#include<iostream>
#include<thread>
#include<chrono>
#include<algorithm>
#include<future>
typedef long long int ull;
 
void findOdd(std::promise<ull>&& OddSumPromise, ull start, ull end) {   // here we use && means the promiseis moved which is requires as promise is not copyable 
	ull Oddsum = 0;
	for (ull i = start;i <= end;++i) {
		if (i & 1)
			Oddsum += i;
	}
    // Uses set_value() on the promise object, which pushes the result to the corresponding future.
	OddSumPromise.set_value(Oddsum);    // it will return the value to the future 
}

int main() {
	ull start = 0, end = 1900000000;

    // first thing is to create a promise object
	std::promise<ull>OddSum;
    // second thing is to create a future object from that promise object
    // there is a state sharing between these two  
    // once the value is set in the promise , it become available to the future 
	std::future<ull>OddFuture = OddSum.get_future();

	std::cout << "Thread created!!" << std::endl;

	std::thread t1(findOdd, std::move(OddSum), start, end);

	std::cout << "Waiting for the reult!!" << std::endl;

    // The main() thread blocks at .get() until the promise is fulfilled via .set_value() in the findOdd thread.
	std::cout << "OddSum" << OddFuture.get() << std::endl;
	std::cout << "completed" << std::endl;
	t1.join();   // // Must join to avoid crash or memory issues
	return 0;
}   

// promise is send to the thread promise.set_value();
// once it is executed it will send it to future object

// promise is like a setter and future is like a getter 





//What is std::future and std::promise ?
//These two are part of the <future> header in C++, and they are used for thread synchronization and communication between threads.


//🔸 Analogy
//Imagine two friends :
//🧑‍💻 One will cook dinner(worker thread).
//🍽️ The other is waiting to eat(main thread).
//But the eater doesn't know when dinner will be ready.
//So the cook promises, “I'll tell you when it’s done.” That’s std::promise.
//And the eater holds the std::future, like a notification slip.When dinner is ready, the promise sets the result, and the future gets it.


// BASIC PROGRAM FOR PROMISE AND FUTURE 


//#include <iostream>
//#include <thread>
//#include <future>
//
//void doWork(std::promise<int> p) {
//    std::this_thread::sleep_for(std::chrono::seconds(2));
//    p.set_value(42); // Set result
//}
//
//int main() {
//    std::promise<int> p;
//    std::future<int> f = p.get_future(); // Get future from promise
//
//    std::thread t(doWork, std::move(p));
//
//    std::cout << "Waiting for result...\n";
//    int result = f.get(); // Blocks until set_value() is called
//    std::cout << "Result is: " << result << "\n";
//
//    t.join();
//    return 0;
//}
//
//
//Key Points :
//
//std::promise<T> is used to set a value(or an exception).
//std::future<T> is used to get that value, possibly waiting until it's ready.
//f.get() blocks until p.set_value(...) is called.   
//future.get() blocks the calling thread until promise.set_value() is called (or an exception is set).

//🔸 Why Use Them ?
//They help :
//Communicate between threads(pass result from one to another).
//Synchronize threads(wait until a task is done).
//Handle exceptions across threads.
//Get return values from a thread function like we do in normal functions.




// there is only one future per promise 
// for multiple use shared_future<>sf=promise_obj.set_future().share(); 


// future.get() can be called once in a program . Use shared_future for mutiple reads


// If the promise is destroyed without setting a value, calling get() on the future throws a std::future_error.

// Promise usually uses heap internally to manage state shared with the future.