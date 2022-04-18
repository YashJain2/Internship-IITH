#include<stdio.h>
#include<omp.h>

int main(){
    //creates default number of threads

    #pragma omp parallel //parallel region starts
    {
        int ID = omp_get_thread_num(); //runtime library function to return thread ID
        printf("hello(%d)",ID);
        printf("hello(%d)\n",ID);
    }
    //end of paralle region
    return 0;
}