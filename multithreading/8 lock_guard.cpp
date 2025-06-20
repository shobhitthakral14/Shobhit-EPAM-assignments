
// syntax  =  std::lock_guard<mutex>lock(m1))

//0. It is very light weight wrapper for owning mutex on scoped basis.
//1. It acquires mutex lock the moment you create the object of lock_guard.
//2. It automatically removes the lock while goes out of scope.
//3. You can not explicitly unlock the lock_guard.
//4. You can not copy lock_guard.


// If an exception is thrown between lock() and unlock(), the unlock() call may never execute, leading to a deadlock.
// so it is safe as it unlocks itself after the scope ends 

#include<iostream>
#include<thread>
#include<mutex>

std::mutex m1;
int buffer = 0;

void task(const char* threadno, int loopfor) {
    // m1.lock();                           // instead of using lock and unlock we can use lock_guard 
	std::lock_guard<std::mutex>lock(m1);    // it is a wrapper for owning mutex on scope basis means unlock itself after the scope end 
	for (int i = 0;i < loopfor;i++) {
		std::cout << threadno   << buffer++ << std::endl;
	}
    // m1.unlock();
}
// manual locking and unlocking is replaced by lock_guard as it is scope based and it is a RAII concept

int main() {
	std::thread t1(task, "T0", 10);
	std::thread t2(task, "T1", 10);
	t1.join();
	t2.join();
	std::cout << "Buffer is :" << buffer << std::endl;
	return 0;
}








//Caution: Manual lock() and unlock() Can Be Dangerous
//What if an exception occurs between lock() and unlock() ?
//→ The mutex might never be released — leading to deadlocks!

//#include<iostream>
//#include<thread>
//#include<mutex>
//
//std::mutex m;
//
//void unsafetask() {
//	m.lock();
//	std::cout << "Thread acquired lock" << std::endl;
//	throw std::runtime_error("something went wrong");
//	m.unlock(); // this line never execute
//}
//
//void anothertask() {
//	std::this_thread::sleep_for(std::chrono::milliseconds(100));
//	std::cout << "Another thread trying to acquire the lock" << std::endl;
//	m.lock();// will block forever because the lock is never relased
//	std::cout << "Another thread acquired lock" << std::endl;
//	m.unlock();
//}

//int main() {
//	try {
//		std::thread t1(unsafetask);
//		std::thread t2(anothertask);
//
//		t1.join();
//		t2.join();
//	}
//	catch (const std::exception& e) {
//		std::cerr << "Exception caught in main :" << e.what() << std::endl;
//	}
//
//
//	std::cout << "finished" << std::endl;
//	return 0;
//}
// THAT IS WHY USE LOCKGUARD WHICH IS RAII CONCEPT SIMILAR TO WHAT WE USE SMART POINTER 