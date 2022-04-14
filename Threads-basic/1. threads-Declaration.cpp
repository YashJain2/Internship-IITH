//Threading in C++
// What do you understand by thread and give one example in C++?

//  In every application there is a default thread which is main(), in side this we create other threads.
//  A thread is also known as lightweight process. Idea is achieve parallelism by dividing a process into multiple threads. 
//    For example:
//    (a) The browser has multiple tabs that can be different threads. 
//    (b) MS Word must be using multiple threads, one thread to format the text, another thread to process inputs (spell checker)
//    (c) Visual Studio code editor would be using threading for auto completing the code. (Intellicence)

// WAYS TO CREATE THREADS IN C++11
// 1. Function Pointers
// 2. Lambda Functions
// 3. Functors
// 4. Member Functions
// 5. Static Member functions


#include<iostream>
#include<thread>
#include<algorithm>

//Functor
class Base{
    public:
    void operator()(int n){
        std::cout<<n<<". Thread is created using Functor(function object)\n";
    }
};


//Non-static member class
class Base1{
    public:
    void run(int n){
        std::cout<<n<<". Thread is created using Class non-static member function\n";
    }
};

//Static member class
class Base2{
    public:
    static void run(int n){
        std::cout<<n<<". Thread is created using Class non-static member function\n";
    }
};

void func(int n){
    std::cout<<n<<". Thread created using function pointer\n";
}

int main(){
    //Function Pointer
    std::thread t1(func,1);

    //Lambda Function
    std::thread t2([](int n){
        std::cout<<n<<". Thread crested using lamba function\n";
    },2);

    //Functor )function object)
    std::thread t3(Base(),3);

    //class member function
    //non-static
    Base1 a;
    std::thread t4(&Base1::run,&a,4);

    //static member function
    std::thread t5(&Base2::run,5);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    return 0;
}