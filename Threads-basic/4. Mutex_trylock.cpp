//try lock() function is used to prevent thread to be in block state waiting to enter in critical section
//it prevents thread to enter in block state using lock() on mutex


#include<iostream>
#include<chrono>
#include<thread>
#include<mutex>

using namespace std;

std::mutex m;
long int counter=0;

void func(){
    for(int i=0;i<100000;i++){
        if(m.try_lock()){
            ++counter;
            m.unlock();
        }
    }
}

int main(){
    thread t1(func);
    thread t2(func);
    t1.join();
    t2.join();
    cout<<counter<<endl;
    return 0;
}

//CS-critical section
//Here both the t1 and t2 threads are trying to access the same func() so in 
//if condition once any thread enters in CS the other did not wait and continue to next statement 
//here in func() i++
//So every time output of the function may vary


//There are several try_lock() methods once discussed here is on mutex
//std::try_lock(t1,t2,t3);
//One on recursive mutex
//etc
