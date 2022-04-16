//DeadLock
#include<iostream>
#include<chrono>
#include<thread>
#include<mutex>

using namespace std;

std::mutex m1,m2;

//deadlock condition as both t1 and t2 hold m1 and m2 critical section and looking for the another critical section
//i.e. hold by the other thread 
void thread1(){
    m1.lock();
    // std::this_thread::sleep_for(std::chrono::seconds(1));
    m2.lock();
    cout<<"Critical section of thread 1\n";
    m1.unlock();
    m2.unlock();
}

void thread2(){
    m2.lock();
    // std::this_thread::sleep_for(std::chrono::seconds(1));
    m1.lock();
    cout<<"Critical section of thread 2\n";
    m2.unlock();
    m1.unlock();
}


int main(){
    thread t1(thread1);
    thread t2(thread2);
    t1.join();
    t2.join();
    return 0;
}