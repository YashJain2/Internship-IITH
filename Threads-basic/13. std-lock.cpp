// TOPIC: std::lock() In C++11

// It is used to lock multiple mutex at the same time.

// IMPORTANT:
// styntax: std::lock(m1, m2, m3, m4);
// 1. All arguments are locked via a sequence of calls to lock(),  try_lock(), or unlock() on each argument.
// 2. Order of locking is not defined (it will try to lock provided mutex in any order and ensure that
//     there is no dead lock).
// 3. It is a blocking call.


// [Example:0] -- No deadlock.
//     Thread 1                    Thread 2
//     std::lock(m1,m2);           std::lock(m1,m2);

// [Example:1] -- No deadlock. 

//     Thread 1                    Thread 2
//     std::lock(m1, m2);          std::lock(m2, m1);

// [Example:2] -- No deadlock. 

//     Thread 1                    Thread 2
//     std::lock(m1, m2, m3, m4);  std::lock(m3, m4);
//                                 std::lock(m1, m2);

// [Example:3] -- Yes, the below can deadlock. 

//     Thread 1                    Thread 2
//     std::lock(m1,m2);           std::lock(m3,m4);
//     std::lock(m3,m4);           std::lock(m1,m2);
#include<iostream>
#include<chrono>
#include<thread>
#include<mutex>

using namespace std;

std::mutex m1,m2;


//example 1
void func1(){
    std::lock(m1,m2);
    cout<<"Task 1 \n";
    m1.unlock();
    m2.unlock();
}

void func2(){
    std::lock(m2,m1);
    cout<<"Task 2 \n";
    m2.unlock();
    m1.unlock();
}

//not understand
int main(){
    thread t1(func1);
    thread t2(func2);
    t1.join();
    t2.join();
    return 0;
}