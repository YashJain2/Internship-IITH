// TOPIC: unique_lock In C++

// NOTES:
// 1. The class unique_lock is a mutex ownership wrapper.
// 2. It Allows:
//     a. Can Have Different Locking Strategies
//     b. time-constrained attempts at locking (try_lock_for, try_lock_until)
//     c. recursive locking
//     d. transfer of lock ownership (move not copy)
//     e. condition variables. (See this in coming videos)

// Locking Strategies
//    TYPE           EFFECTS(S)
// 1. defer_lock  do not acquire ownership of the mutex.
// 2. try_to_lock  try to acquire ownership of the mutex without blocking.
// 3. adopt_lock  assume the calling thread already has ownership of the mutex.


#include<iostream>
#include<chrono>
#include<thread>
#include<mutex>

using namespace std;

std::mutex m;
int buffer=0;


//simple unique_lock()
void func(const char* threadNumber, int loopFor){
    std::unique_lock<mutex> lock(m);
    for(int i=0;i<loopFor;i++){
        buffer++;
        cout<<threadNumber << " " << buffer << endl; 
    }
}


//unique lock() with defer_lock() strategy
void func(const char* threadNumber, int loopFor){
    std::unique_lock<mutex> lock(m,std::defer_lock);
    lock.lock();//explicitly define lock for the mutex to transfer ownership right
    for(int i=0;i<loopFor;i++){
        buffer++;
        cout<<threadNumber << " " << buffer << endl; 
    }
}

int main(){
    thread t1(func,"T1",10);
    thread t2(func,"T2",10);
    t1.join();
    t2.join();
    cout<<buffer<<endl;
    return 0;
}
