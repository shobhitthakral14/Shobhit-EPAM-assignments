// 0. std::try_lock() tries to lock all the mutex passed in it one by one in given order.
// 1. On success this function returns -1 otherwise it will return 0-based mutex index number which it could not lock.
// 2. If it fails to lock any of the mutex then it will release all the mutex it locked before.
// 3. If a call to try_lock results in an exception, unlock is called for any locked objects before re-throwing.


// std::try_lock(m1,m2,m3,.....);



#include<iostream>
#include<mutex>
#include<chrono>
#include<thread>

using namespace std;

int X=0;
int Y=0;

std::mutex m1,m2;

void dosomework(int sec)
{
    std::this_thread::sleep_for(std::chrono::seconds(sec));
}

void incrementXY(int &XorY ,std::mutex& m ,const char* desc)
{
    for(int i=0;i<5;i++)
    {
        m.lock();
        ++XorY;
        cout<<desc<<XorY<<endl;
        m.unlock();
        dosomework(1);
    }
}

void consumeXY()
{
    int usecount=5;
    int XplusY=0;
    while(1)
    {
        int lockresult=std::try_lock(m1,m2);
        if(lockresult==-1)
        {
            if(X!=0 && Y!=0)
            {
                --usecount;
                XplusY+=X+Y;
                X=0;
                Y=0;
                cout<<"XplusY"<<XplusY<<endl;
            }
            m1.unlock();
            m2.unlock();
            if(usecount==0) break;
        }
    }
}

int main()
{
    std::thread t1(incrementXY,std::ref(X),std::ref(m1),"X");
    std::thread t2(incrementXY,std::ref(Y),std::ref(m2),"Y");
    std::thread t3(consumeXY);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}