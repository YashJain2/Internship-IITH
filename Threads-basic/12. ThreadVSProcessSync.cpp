// TOPIC: Thread OR Process Synchronization

// NOTE: we will use only thread examples to explain this topic.

// POINTS:
// 1.0 Thread Or Process synchronize to access critical section.
// 2.0 Critical section is one or collection of program statements which should be executed by only one thread or process at a time.

#include<iostream>
#include<chrono>
#include<thread>
#include<mutex>

using namespace std;
int balance=0;

std::mutex m1;

void func(int money){
    if(money<=0){
        cout<<"Balance: "<<balance<<endl;
        return;
    }
    m1.lock();
    balance+=money;
    m1.unlock();
    cout<<"Balance: "<<balance<<endl;
}


//not understand
int main(){
    thread t1(func,100);
    thread t2(func,200);
    t1.join();
    t2.join();
    return 0;
}