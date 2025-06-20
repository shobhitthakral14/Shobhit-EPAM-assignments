//Few important points to remember while using "condition variables" are as follows :
//1. Condition variables allow us to synchronise threads via notifications.
//a.notify_one();
//b.notify_all();
//2. You need mutex to use condition variable
//3. Condition variable is used to synchronise two or more threads.
//4. Best use case of condition variable is Producer / Consumer problem.
//5. Condition variables can be used for two purposes :
//a.Notify other threads
//b.Wait for some condition




#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>

std::condition_variable cv;
std::mutex m;
long balance = 0;

void addMoney(int money) {  
	std::lock_guard<std::mutex>lg(m);                                               // after mutex is released by the unique_lock it is locked here 
	balance += money;
	std::cout << "Amount Added Current Balance " << balance << std::endl;
	cv.notify_one();                                                                // this will notify the withrawMoney function to acqire the lock
}


void withdrawMoney(int money) {
	std::unique_lock<std::mutex>ul(m);
    // here we have conditional variable . wait  
	cv.wait(ul, [] {                                                        // waiting by releasing mutex   it will release the mutex automatically 
		return (balance != 0) ? true : false;
		});

	if (balance >= money) {
		balance -= money;
		std::cout << "Amount deducted :" << money << std::endl;
	}
	else {
		std::cout << "Amount can't be Deducted, Current balance is less than " << money << std::endl;
	}

	std::cout << "Current Balance is :" << balance << std::endl;
}

int main() {
	std::thread t1(withdrawMoney, 500);
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::thread t2(addMoney, 500);
	t1.join();
	t2.join();
	return 0;
}