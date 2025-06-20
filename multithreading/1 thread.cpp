// This comes in cpp 11

// Multithreading allows a program to run multiple threads concurrently, enabling parallelism and better CPU utilization.

// Performance improvement on multi-core systems
// Responsiveness in UI apps
// Efficient I/O operations


// A thread is a light weight process , idea is to achieve parallelism by dividing a process into multiple threads 

// if there is no thread so there is only 1 thread which is main 


// ways to create a thread 

// function pointer
// functor 
// lambdas
// member functions 
// static member functions 


#include<iostream>
#include<thread>
#include<chrono>

typedef unsigned long long ull;

ull Oddsum = 0, Evensum = 0;

void findEven(ull start, ull end) {
    for (ull i = start; i <= end; ++i) {
        if ((i & 1) == 0) {
            Evensum += i;
        }
    }
}

void findOdd(ull start, ull end) {
    for (ull i = start; i <= end; ++i) {
        if ((i & 1) == 1) {
            Oddsum += i;
        }
    }
}

int main() {
    ull start = 0, end = 1900000000;

    auto startTime = std::chrono::high_resolution_clock::now();

    // syntax for function pointer  
    std::thread t1(findEven, start, end);
    std::thread t2(findOdd, start, end);

    // joining the threads to the main thread 
    t1.join();
    t2.join();

    auto endTime = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);

    std::cout << "Even Sum: " << Evensum << "\n";
    std::cout << "Odd Sum: " << Oddsum << "\n";
    std::cout << "Time taken: " << duration.count()/1000000 << " ms\n";

    return 0;
}


// if we join() on the same thread twice it will call std::terminate 

// If you skip join(), your thread is still running when main() returns — causing undefined behavior.





// THREAD CALLING 

#include<iostream>
#include<thread>
// There are 5 different types we can create thread in cpp 11 using callable object

// NOTE:
// if we create multiple thread at same time it does not guarantee which will start first
// it depends on the operating system’s thread scheduler, which can vary across systems and runs. 

//// 1.) Function pointer 
//// this is very basic form of thread creation

//void fun(int x) {
//	while (x-- > 0) {
//		std::cout << x << std::endl;
//	}
//}
//int main() {
//	std::thread t(fun, 10);
//	t.join();
//	return 0;
//}

// 2.) lambda expression

//int main() {
//  //auto fun = [](int x) {
//	while (x-- > 0) {
//		std::cout << x << std::endl;
//	}
//};
//	std::thread t(fun, 10);
//	t.join();
//	return 0;
//}


// we can directly inject lambda at thread creation time
//int main() {
//	std::thread t([](int x) {
//		while (x-- > 0) {
//			std::cout << x << std::endl;
//		}
//		}, 10);
//	t.join();
//	return 0;
//}


//3.0 function object (functor)

//class base {
//public:
//	void operator()(int x) {
//		while (x-- > 0) {
//			std::cout << x << std::endl;
//		}
//	}
//};
//int main() {
//	std::thread t(base(), 10);
//	t.join();
//	return 0;
//}



// 4.) Non-static member function 

//class base {
//public:
//	void run(int x) {
//		while (x-- > 0) {
//			std::cout << x << std::endl;
//		}
//	}
//};
//int main() {
//	base b;
//	std::thread t(&base::run, b, 10);
//	t.join();
//	return 0;
//}



// 5.) static member function
//class base {
//public:
//	static void run(int x) {
//		while (x-- > 0) {
//			std::cout << x << std::endl;
//		}
//	}
//};
//int main() {
//	std::thread t(&base::run, 10);
//	t.join();
//	return 0;
//}



// as this is static we dont need any object as it is of class not of object 