#include<bits/stdc++.h>
#include<iostream>
#include <fstream>
#include <chrono>
#include <sys/time.h>
#include<ctime>
#include<list>
#include<omp.h>
#define NUM_THREADS 100
using namespace std;
using namespace std::chrono;
int countTriangle=0;

void displayAdjList(list<int> adj_list[], int v) {
    // omp_set_num_threads(NUM_THREADS);
    // #pragma omp parallel
    // {
    //     #pragma omp for
        for(int i = 0; i<v; i++) 
        {
            vector <int> a;
            vector <int> b;
            // cout << i << "---> ";
            // list<int> :: iterator temp1;
            omp_set_num_threads(NUM_THREADS);
            #pragma omp parallel 
            {
                // int id,nthrds;
                // id = omp_get_thread_num();
                // nthrds = omp_get_num_threads();
                auto temp1 = adj_list[i].begin();
                #pragma openmp for
                for( ;temp1 != adj_list[i].end();temp1++)
                {
                    #pragma omp critical
                    {
                        a.push_back(*temp1);
                    }
                }
            }
            
            omp_set_num_threads(NUM_THREADS);
            #pragma omp parallel
            {
                auto it = adj_list[i].begin();
                #pragma openmp for
                for(; it != adj_list[i].end(); ++it)
                {
                    //stores the list of neighbours in *it pointer
                    // cout << *it << "  ";
                    list<int> :: iterator temp;
                    for(temp = adj_list[*it].begin(); temp != adj_list[*it].end();temp++)
                        b.push_back(*temp);
                    // #pragma omp parallel for
                    for(int ii=0;ii<b.size();ii++){
                        if(b[ii]==i)
                        {
                            continue;
                        }
                        else
                        {
                            // #pragma omp parallel for
                                for(int jj=0;jj<a.size();jj++)
                                {
                                    if(a[jj]==*it)
                                    {
                                        continue;
                                    }
                                    else
                                    {
                                        if(a[jj]==b[ii])
                                        {
                                            #pragma omp critical
                                            {
                                                countTriangle++;
                                            }
                                        }
                                    }
                                }
                                                    
                        }
                    }
                    b.clear();
                }
            }
            // cout << endl;
        a.clear();
        }   
    // }
    cout<<"No of triangles in the given adjaceny list: "<<countTriangle/6;
}

void add_edge(list<int> adj_list[], int u, int v) {   
//add v into the list u, and u into list v
   adj_list[u].push_back(v);
   adj_list[v].push_back(u);
}




int main()
{
    cout<<"Inside\n";
    int v = 36691;
    list<int> adj_list[36691];
    cout<<"Inside\n";
    std::ifstream fs("C:/Users/user/Desktop/Internship/Counting-Triangle/input1.txt");
    cout<<"Inside\n";
    if( fs.is_open() )
    {
        int a, b;
        cout<<"Inside\n";
        while (fs >> a >> b)
        {
            // cout<<a<<" "<<b<<endl;        // process pair (a,b)
            add_edge(adj_list, a, b);
        }
        cout<<"Inside\n";
        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        displayAdjList(adj_list, v);
        high_resolution_clock::time_point t2 = high_resolution_clock::now();  
        double dif = duration_cast<seconds>( t2 - t1 ).count();
        printf ("\nElasped time is %lf seconds.\n", dif );
    }
    else{
        cerr << ">Error by opening the file\n";
        return -2;
    } 
    return 0;
}




// ifstream inFile;
//     // open the file stream
//     inFile.open("C:/Users/user/Desktop/Internship/Counting-Triangle/input1.txt");
//     // check if opening a file failed
//     if (inFile.fail()) 
//     {
//         cerr << "Error opeing a file" << endl;
//         inFile.close();
//     }
//     else
//     {
//         cout<<"Success\n";
//     }
