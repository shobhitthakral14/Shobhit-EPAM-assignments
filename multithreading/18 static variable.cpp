#include <iostream>
#include <mutex>
#include <thread>

std::mutex m;
static int s = 0;

void fun()
{
    int count = 1000;
    while (count--)
    {
        // m.lock();
        ++s;
        // m.unlock();
    }
}

int main()
{
    std::thread t1(fun);
    std::thread t2(fun);

    t1.join();  // Wait for t1 to finish
    t2.join();  // Wait for t2 to finish

    std::cout << "Final value of s: " << s << std::endl;

    return 0;
}
