// TOPIC: std::lock_guard In C++
 
// NOTES:
// 0. It is very light weight wrapper for owning mutex on scoped basis.
// 1. It acquires mutex lock the moment you create the object of lock_guard.
// 2. It automatically removes the lock while goes out of scope.
// 3. You can not explicitly unlock the lock_guard.
// 4. You can not copy lock_guard.


#include<iostream>
#include<chrono>
#include<thread>
#include<mutex>

using namespace std;

std::mutex m;
int buffer=0;

void func(const char* threadNumber, int loopFor){
    std::lock_guard<mutex> lock(m);
    for(int i=0;i<loopFor;i++){
        buffer++;
        cout<<threadNumber << " " << buffer << endl; 
    }
}
    
int main(){
    thread t1(func,"T1 ",10);
    thread t2(func,"T2 ",10);
    t1.join();
    t2.join();
    cout<<"Buffer "<<buffer<<endl;
    return 0;
}
