

// syntax -> std::unique_lock<mutex>lock(m1);


//1. The class unique_lock is a mutex ownership wrapper.

//2. It Allows :
//a.Can Have Different Locking Strategies
//b.time - constrained attempts at locking (try_lock_for, try_lock_until)
//c.recursive locking
//d.transfer of lock ownership(move not copy)
//e.condition variables. 



//Locking Strategies
//TYPE           EFFECTS(S)
//1. defer_lock  do not acquire ownership of the mutex.
//2. try_to_lock  try to acquire ownership of the mutex without blocking.
//3. adopt_lock  assume the calling thread already has ownership of the mutex.



#include<iostream>
#include<mutex>
#include<thread>
using namespace std;


std::mutex m1;
int buffer=0;

// EXAMPLE 1

// void task(const char* threadnumber , int loopfor)
// {
//     std::unique_lock<mutex> lock(m1);      // automatically calls lock on mutex
//     for(int i=0 ;i<loopfor;i++)
//     {
//         buffer++;
//         cout<<threadnumber<<buffer<<endl;
//     }
        //Destructor automatically unlocks when lock goes out of scope.
// }


// int main()
// {
//     thread t1(task,"T1",10);
//     thread t2(task,"T2",10);
//     t1.join();
//     t2.join();
//     return 0;

// }




// EXAMPLE 2      defer_lock 


void task(const char* threadnumber , int loopfor)
{
    std::unique_lock<mutex> lock(m1 ,std::defer_lock);
    lock.lock();      // will have to tell explicitly where to lock 
    for(int i=0 ;i<loopfor;i++)
    {
        buffer++;
        cout<<threadnumber<<buffer<<endl;
    }

    // lock.unlock() is not required as it will be unlocked in the destructor of the unique_lock 
}


int main()
{
    thread t1(task,"T1",10);
    thread t2(task,"T2",10);
    t1.join();
    t2.join();
    return 0;

}
// Useful for conditional or timed locking.

// Still auto-unlocks at the end of scope via destructor.








// EXAMPLE 3     TRY_TO_LOCK

void task(const char* threadnumber, int loopfor) {
    std::unique_lock<std::mutex> lock(m1, std::try_to_lock);  // attempt to lock

    // owns_lock checks if successful return true and enter critical section 
    if (lock.owns_lock()) {
        for (int i = 0; i < loopfor; i++) {
            buffer++;
            cout << threadnumber << " " << buffer << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
    } else {
        cout << threadnumber << " could not acquire lock.\n";
    }

    // lock will automatically unlock when it goes out of scope
}

int main() {
    thread t1(task, "T1", 10);
    thread t2(task, "T2", 10);
    t1.join();
    t2.join();
    return 0;
}

// This strategy is ideal when you don’t want a thread to wait if the resource is busy — useful in low-latency or UI-related scenarios.







// EXAMPLE 4   adopt_lock 


void task(const char* threadnumber, int loopfor) {
    m1.lock();  // Manually lock the mutex

    // Now tell unique_lock to adopt this existing lock
    std::unique_lock<std::mutex> lock(m1, std::adopt_lock);

    for (int i = 0; i < loopfor; i++) {
        buffer++;
        cout << threadnumber << " " << buffer << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    // No need to call unlock — unique_lock will handle it
}






// You manually lock the mutex using m1.lock().
// Then pass std::adopt_lock to std::unique_lock to tell it:
// “This mutex is already locked — just take over responsibility.”
// From this point on, unique_lock will unlock the mutex when it goes out of scope.
// ❗ Important: Do not use adopt_lock unless you've already locked the mutex manually, or it will cause undefined behavior.















//What it is :
// A more flexible and feature - rich wrapper than lock_guard.
//Supports delayed locking, manual unlock / lock, lock ownership transfer, and more.




//Feature	Supported :
//Deferred Locking	
//Try - lock(non - blocking)	
//Manual lock / unlock	
//Transfer ownership	
//Works with std::condition_variable	




//std::unique_lock Locking Strategies
// std::mutex m;

// // 1. Immediate locking (like lock_guard)
// std::unique_lock<std::mutex> lock1(m);

// // 2. Defer locking
// std::unique_lock<std::mutex> lock2(m, std::defer_lock); // No lock yet 
// lock2.lock();  // Now explicitly lock it

// // 3. Try-lock
// std::unique_lock<std::mutex> lock3(m, std::try_to_lock);
// if (lock3.owns_lock()) {
//    // acquired successfully
// }
// else {
//    // couldn't acquire lock
// }

// // 4. Adopt already locked mutex
// m.lock();
// std::unique_lock<std::mutex> lock4(m, std::adopt_lock); // assumes you already locked it




//?? Summary Table
//
//
//Feature	std::              lock_guard	                                                    std::unique_lock
//Immediate Lock	              ?																?
//Delayed Lock				  ?																?(std::defer_lock)
//Manual Unlock				  ?																?(lock.unlock())
//Try - Lock					  ?																?(std::try_to_lock)
//Ownership Transfer			  ?																?(movable)
//Works with cond.variable	  ?																?
//Performance(lightweight)	  ?(faster)														?(slightly heavier)
//Exception Safety			  ?																?








//When to Use What?
//Situation	                                                                                Use
//Simple scope - based lock, no manual control needed	                                       lock_guard
//Need to manually unlock / re - lock inside a function	                                   unique_lock
//Using std::condition_variable	                                                           unique_lock
//Try - lock or deferred lock strategy needed	                                               unique_lock
//Tight performance - critical sections	                                                   lock_guard



// pro tip
//Prefer lock_guard for simplicity.
//Use unique_lock only when you really need the advanced flexibility.
