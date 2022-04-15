//thread basics
//joining and detaching the threads with example
//you cannot doublejoin or double detach a particular thread object
//Join and Detach both are destructors of thread object and must be called upon each and every thread after termination

#include<iostream>
#include<chrono>
#include<thread>

using namespace std;

void run(int n){
    while(n--){
        cout<<"Hello to thread function\n";
    }
    std::this_thread::sleep_for(chrono::seconds(3));
}

int main(){
    cout<<"Before thread execution\n\n";
    thread t1(run,5);
    if(t1.joinable())
        t1.join();
    //waits for join to return after 3 seconds
    cout<<"\n\n\nAfter thread join to main function";

    //detach
    thread t2(run,10);

    if(t2.joinable())
        t2.detach();
    //after detaching we cant call join()

    if(t2.joinable())
        t2.join();

    cout<<"\n\nOutput of t2 thread\n\n";
    std::this_thread::sleep_for(chrono::seconds(3));
    //waiting for t2 to complete
    //main thread will terminate irrespective of the thread t2
    cout<<"\nEnd of the main function after detachind the thread t2\n";
    return 0;
}