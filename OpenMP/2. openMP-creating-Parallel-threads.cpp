#include<iostream>
#include<omp.h>
using namespace std;

int main(){
    // omp_set_num_threads(4);
    //runtime function to request the certain number of threads
    double A[1000];
    #pragma omp parallel num_thread(3) //creates 4 threads parallel region
    {
        int ID = omp_get_thread_num();
        // func(ID,A);
        //a single function is used by multiple threads 
        //works over shared data array A[1000]
    }
    printf("All Done\n");
    return 0;
}