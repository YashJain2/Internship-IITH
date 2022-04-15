// 0. std::timed_mutex is blocked till timeout_time or the lock is aquired and returns true if success otherwise false.
// 1. Member Function:
//    a. lock 
//    b. try_lock
//    c. try_lock_for    --- These two functions makes it different from mutex.
//    d. try_lock_until  ---
//    e. unlock
// EXAMPLE: try_lock_for();
// Waits until specified timeout_duration has elapsed or the lock is acquired, whichever comes first.
// On successful lock acquisition returns true, otherwise returns false.

#include<iostream>
#include<chrono>
#include<thread>
#include<mutex>

using namespace std;

//different member
std::timed_mutex m;
// std::mutex m1,m2;
int amount=0;

//try_lock_for()
void increment (int i){
    if(m.try_lock_for(chrono::seconds(1 ))){
        ++amount;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        cout<<"Thread " << i << " Entered\n";
        m.unlock();
    }
    else{
        cout<<"Thread " << i << " couldn't Entered\n";
    }
}

//try_lock_until()
void increment1 (int i){
    auto now = std::chrono::steady_clock::now();
    if(m.try_lock_until(now + std::chrono::seconds(2))){
        ++amount;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        cout<<"Thread " << i << " Entered\n";
        m.unlock();
    }
    else{
        cout<<"Thread " << i << " couldn't Entered\n";
    }
}
    
int main(){
    thread t1(increment1,1);
    thread t2(increment1,2);
    t1.join();
    t2.join();
    return 0;
}
