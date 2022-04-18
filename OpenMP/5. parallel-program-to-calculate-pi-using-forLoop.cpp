//parallel program using 10 threads to calculate the value of using openMP for loop
#include<iostream>
#include<omp.h>
#define NUM_THREADS 100

using namespace std;

long int num_steps=100000;
double step;

int main(){
    double sum[NUM_THREADS],pi=0.0;
    step = 1.0/(double(num_steps));
    omp_set_num_threads(NUM_THREADS);
    #pragma omp parallel
    {
        int ID = omp_get_thread_num();
        double x;
        sum[ID] =0.0;
        #pragma omp for
        for(long int i=0;i<num_steps;i++)
        {
            x = (i+0.5)*step;
            sum[ID] += (4.0/(1.0+(x*x)));
        }
    }
    for(int i=0;i<NUM_THREADS;i++)
    {
        pi += (sum[i]*step);
    }
    cout<<pi<<endl;
    return 0;
}