//Mutex in C++ Threading: Why mutex ? Why Race Condition and How we can solve it? What is Critical Section
// MUTEX: Mutual Exclusion : is used to avoid race condition  we use lock() and unlock() on mutex threads

// Race Condition : is a situation where 2 or more threads /process happen to change common data at same time
//Such conditions are needed to be avoided and we have to protect data in Critical Section
#include<iostream>
#include<chrono>
#include<thread>
#include<mutex>

using namespace std;
int balance =1000;
std::mutex m;

void addMoney(){
    m.lock();
    balance+=100;
    m.unlock();
}

int main(){
    thread t1(addMoney);
    thread t2(addMoney);

    t1.join();
    t2.join();

    cout<<balance<<endl;

    return 0;
}

