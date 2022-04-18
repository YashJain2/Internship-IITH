//with openMP we need -fopenmp to compile our code

#include<iostream>
#include<omp.h>
using namespace std;

int main(){
    //creates default number of threads
    #pragma omp parallel
    {
        int iD = omp_get_thread_num();
        cout<< "hello "<<iD<<'\n';
        cout<< "world "<<iD<<'\n';
    }
    return 0;
}