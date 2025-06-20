//Mutex: Mutual Exclusion    (samjhota)
//RACE CONDITION :
//0. Race condition is a situation where two or more threads / process happens to change a common data at the same time.
//1. If there is a race condition then we have to protect it and the protected section is called critical section / region.
//MUTEX :
//	0. Mutex is used to avoid race condition.
//	1. We use lock(), unlock() on mutex to avoid race condition.


#include<iostream>
#include<thread>
#include<mutex>

// this mutex is common for both the threads 
std::mutex m;
int myAmount = 0;


void addMoney() {
	m.lock(); 
	++myAmount;        // this is race condition    // this is critical section 
	m.unlock();
}

int main() {
	std::thread t1(addMoney);

	std::thread t2(addMoney);


	t1.join();
	t2.join();

	std::cout << myAmount << std::endl;

	return 0;
}

