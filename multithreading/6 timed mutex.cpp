
 //"Timed Mutex In C++ Threading (std::timed_mutex)"

//And few points to remember about timed mutex is as follows :
//0. std::timed_mutex is blocked till timeout_time or the lock is acquired and returns true if success
//otherwise false.
//1. Member Function :
//a.lock
//b.try_lock
//c.try_lock_for-- - \ These two functions makes it different from mutex.
//d.try_lock_until-- - /
//e.unlock
//
//EXAMPLE : try_lock_for();
//Waits until specified timeout_duration has elapsed or the lock is acquired, whichever comes first.
//On successful lock acquisition returns true, otherwise returns false




//// try_lock_for
//#include<iostream>
//#include<thread>
//#include<mutex>
//#include<chrono>
//
//int myAmount = 0;
//std::timed_mutex m;
//
//void increment(int i) {
//	if (m.try_lock_for(std::chrono::seconds(1))) { // here thread wait for specific time here it is 1 sec if he able to acquire the lock then he entered the critical section otherwise after specific period of time it return false
//		++myAmount;
//		std::this_thread::sleep_for(std::chrono::seconds(2));
//		std::cout << "Thread :" << i << "Entered" << std::endl; 
//		m.unlock();
//	}
//	else {
//		std::cout << "Thread " << i << "Could't Enter" << std::endl;
//	}
//}
//
//int main() {
//	std::thread t1(increment, 1);
//	std::thread t2(increment, 2);
//
//	t1.join();
//	t2.join();
//
//	std::cout << myAmount << std::endl;
//	return 0;
//}



// try_lock_until
//#include<iostream>
//#include<thread>
//#include<mutex>
//#include<chrono>
//
//int myAmount = 0;
//std::timed_mutex m;
//
//void increment(int i) {
//	auto now = std::chrono::steady_clock::now();
//	if (m.try_lock_until(now + std::chrono::seconds(2))) {
//		++myAmount;
//		std::this_thread::sleep_for(std::chrono::seconds(1));
//		std::cout << "Thread :" << i << "Entered" << std::endl; 
//		m.unlock();
//	}
//	else{
//		 std::cout << "Thread " << i << "Could't Enter" << std::endl;
//	}
//}
//int main() {
//	std::thread t1(increment, 1);
//	std::thread t2(increment, 2);
//
//	t1.join();
//	t2.join();
//
//	std::cout << myAmount << std::endl;
//	return 0;
//}