//sequential approach

#include<iostream>
#include<iomanip>
#include<omp.h>
#define NUM_THREADS 2
using namespace std;

static long num_steps=100000;
double step;

double piFunc (double step, int start, int end){
    double x,sum=0.0;
    for(;start<end;start++){
        x = (start+0.5)*step;
        sum += (4.0/(1.0+(x*x)));
    }
    return sum;
}

//using numerical integration
int main (){
    // int i =0 ;
    // double pi, sum=0;
    // step = 1.0/(double(num_steps));
    // sum = piFunc(step,i,num_steps);
    // pi= step*sum;
    // cout<<pi<<endl;

    int i ,nthreads;
    double pi;
    step = 1.0/(double(num_steps));
    //sets the thread requirement to NUM_THREADS
    omp_set_num_threads(NUM_THREADS);
    //parallel section starts
    #pragma omp parallel
    {
        //threads variables 
        //specific to each threads
        int i, id, nthrds;
        double x,sum;
        id = omp_get_thread_num();
        nthrds = omp_get_num_threads();
        //main thread writes the number of thread
        if(id==0)
            nthreads=nthrds;
        
        //for loop for each specific thread
        //Assuming thread with id = 1, 2 are there only
        //hence for(i=1;i<100000;i+=2) for threadID 1
        //hence for(i=2;i<100000;i+=2) for threadID 2
        //both will run in parallel 
        for(i=id,sum=0.0;i<num_steps;i+=nthrds)
        {
            x = (i+0.5)*step;
            sum += (4.0/(1.0+(x*x)));
        }
        //only one thread can have access at same time
        #pragma omp critical
        {
            pi += sum*step;
        }
    }

    cout<<  pi<<endl;
    return 0;
}