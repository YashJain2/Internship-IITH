#include<iostream>
#include<omp.h>
#define NUM_THREADS 10
using namespace std;



int main(){
    int thread_sum[NUM_THREADS];
    omp_set_num_threads(NUM_THREADS);
    #pragma omp parallel
    {
        int ID = omp_get_thread_num();
        #pragma omp for
        for(int i=0;i<21;i++)
        {
            cout<<"ThreadID "<<ID<<"\tValue of i "<<i<<"\n";
        }
    }
}