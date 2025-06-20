//std::mutex::try_lock() On Mutex In C++11 Threading.

//Few points to remember about the try_lock is as follows :
//0. try_lock() tries to lock the mutex .Returns immediately . On successful lock acquisition returns true otherwise returns false.
//1. If try_lock() is not able to lock mutex, then it doesn't get blocked that's why it is called non-blocking.
//2. If try_lock is called again by the same thread which owns the mutex, the behaviour is undefined.
//It is a dead lock situation with undefined behaviour. (if you want to be able to lock the same mutex by same thread more than one time the go for recursive_mutex)


//There are so many try_lock function
//1. std::try_lock
//2. std::mutex::try_lock
//3. std::shared_lock::try_lock
//4. std::timed_mutex::try_lock
//5. std::unique_lock::try_lock
//6. std::shared_mutex::try_lock
//7. std::recursive_mutex::try_lock
//8. std::shared_timed_mutex::try_lock
//9. std::recursive_timed_mutex::try_lock



#include<iostream>
#include<thread>
#include<mutex>

int counter = 0;
std::mutex mtx;

void increaseTheCounterFor100000Time(){
	for (int i = 0;i <100000;i++) {
		mtx.lock();
		++counter;
		mtx.unlock();
	}

}

int main() {
	std::thread t1(increaseTheCounterFor100000Time);
	std::thread t2(increaseTheCounterFor100000Time);
	t1.join();
	t2.join();
	std::cout << counter << std::endl;
// it always give us the anwer 2 lakh as std::mutex::lock() is a blocking state if any thread is not able acquire the lock then it wait until he cant get lock
	return 0;
}





// using try_lock() it gives us the random value if thread able to acquire the lock then it is able to increment 
//the counter otherwiswe it will return skip which result in skipping of its chance
// which results in different results as expected





int counter = 0;
std::mutex mtx;

void increaseTheCounterFor100000Time() {
	for (int i = 0;i < 100000;i++) {
		if (mtx.try_lock()) { // return true if able to acquire the lock and return false if not , that is why we cant get exact 2 lakh here
			++counter;
			mtx.unlock();
		}
	}
}

int main() {
	std::thread t1(increaseTheCounterFor100000Time);
	std::thread t2(increaseTheCounterFor100000Time);
	t1.join();
	t2.join();
	std::cout << counter << std::endl; 
	return 0;
}