//try lock() function is used to prevent thread to be in block state waiting to enter in critical section
//it prevents thread to enter in block state using lock() on mutex
//std::try_lock(m1,m2,m3,m4.....) tries to lock all mutex in given order
//on success -1 and on failure returns 0-based mutex index for that mutex
//if it fails it will release the lock from rest of the locked objects
//If a call to try_lock results in an exception, unlock is called for any locked objects before re-throwing.


#include<iostream>
#include<chrono>
#include<thread>
#include<mutex>

using namespace std;

std::mutex m1,m2;

//not understand
int main(){
    // thread t1(func);
    // thread t2(func);
    // t1.join();
    // t2.join();
    return 0;
}
