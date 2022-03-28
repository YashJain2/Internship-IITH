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
