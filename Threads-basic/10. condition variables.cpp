// TOPIC: Condition Variable In C++ Threading

// NOTES:
// 1. Condition variables allow us to synchronize threads via notifications.
//    a. notify_one();
//    b. notify_all();
// 2. You need mutex to use condition variable
// 3. Condition variable is used to synchronize two or more threads.
// 4. Best use case of condition variable is Producer/Consumer problem.
// 5. Condition variables can be used for two purposes:
//     a. Notify other threads
//     b. Wait for some condition


#include<iostream>
#include<chrono>
#include<thread>
#include<condition_variable>
#include<mutex>

using namespace std;

std::mutex m;
std::condition_variable c;
int balance=0;

void addMoney(int money){
    std::lock_guard<mutex> lg(m);
    balance+=money;
    cout<<"Amount added to the Account: "<<balance<<endl;
    c.notify_one();
}

void withdrawMoney(int money){
    std::unique_lock<mutex> ul(m);
    c.wait(ul, [] { return (balance!=0) ? true : false; });
    if(balance<money){
        cout<<"Amount cannot be withdrawn as balance is less than the "<<money<<endl;
    }
    else{
        cout<<"Amount Deducted: "<<money<<endl;
        balance-=money;
    }
    cout<<"Current balance is: "<<balance<<endl;
}

int main(){
    thread t1(withdrawMoney,4000);
    thread t2(addMoney,1000);
    t1.join();
    t2.join();
    return 0;
}
