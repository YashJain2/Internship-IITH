// DESCRIPTION :
// In this video we will learn about how std::promise and std::future and how they work together to synchronize threads.
// Basically std::promise is sent to the called thread and once the value is ready 
// we set that value in promise object, now at calling thread side we get that value 
// using std::future object which was created using std::promise object before 
// sending it to the called thread. 
// And this is how we receive value from one thread to another in synchronization.

#include<iostream>
#include<chrono>
#include<thread>
#include<mutex>
#include<future>
using namespace std;
typedef long long int ull;

void oddSum(std::promise<ull> && oddSumPromise,ull start, ull end){
    ull sum=0;
    for(ull i=start;i<=end;i++){
        if(i&1){
            sum+=i;
        }
    }
    oddSumPromise.set_value(sum);
}

int main(){
    ull start=0,end=199999;
    std::promise<ull> odd;
    std::future<ull> oddFuture = odd.get_future();
    cout<<"Thread created\n";
    std::thread t1(oddSum,std::move(odd),start,end);
    cout<<"Waiting for results\n";
    cout<<"Sum: "<< oddFuture.get()<<endl;
    return 0;
}
