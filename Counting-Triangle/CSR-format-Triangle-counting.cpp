// Representing a Undirecetd Graph in CSR format in three 1-D array
// Also excluding the case for self loop
#include <bits/stdc++.h>
#include <omp.h>
#include<chrono>
#define NUM_THREADS 10
using namespace std;
typedef std::vector<int> vi;
typedef vector<vector<int> > matrix;

// Sparse matrix are those where number of zeros in graph are much more than the present values

int main()
{
    // enter the no of vertices
    int n = 6;

    // No. of edges in the undirected graph
    int Nz = 0;

    // Compressed Sparse Matrix Representation using Yale Format
    // Creating three 1-D array
    vi rowptr;
    vi column;
    vi values;

    // intializing the rowptr[0]=0
    rowptr.push_back(0);

    // Number of non-zeros elements
    int nonZero = 0, temp = 0;

    matrix a(n);
    // initializing the matrix
    for (int i = 0; i < n; i++)
    {
        int col = 5;
        a[i] = vector<int>(col);

        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            // counting and adding values to the values array
            if (i < j && a[i][j] != 0)
            {
                Nz++;
                nonZero++;
                values.push_back(a[i][j]);
                column.push_back(j);
            }
        }

        // adding row pointers
        if (i > 0)
        {
            int x = rowptr[i - 1] + temp;
            rowptr.push_back(x);
        }
        temp = nonZero;
        nonZero = 0;
    }
    rowptr.push_back(rowptr[n - 1] + temp);

    cout << "Number of non-zero values(Edges): " << Nz << endl;

    // Printing the matrix
    cout << "\nMatrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    // Printing CSR for the given matrix
    // Undirected Graph
    cout << "\nCSR:\n";
    for (int i = 0; i < rowptr.size(); ++i)
    {
        cout << rowptr[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < column.size(); ++i)
    {
        cout << column[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < values.size(); ++i)
    {
        cout << values[i] << " ";
    }
    cout << endl;

    // Finding the degree of each node
    cout << "\nDegree of each node:\n";
    vi degree;
    for (int i = 0; i < n; i++)
    {
        degree.push_back(rowptr[i + 1] - rowptr[i]);
    }
    for (int i = 0; i < Nz; i++)
    {
        degree[column[i]] += 1;
    }
    for (int i = 0; i < n; i++)
    {
        cout << degree[i] << " ";
    }
    cout << "\n";

    // printing the edge list
    cout << "\nPrinting the edge list:\n";
    int rowPointer = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = rowPointer; j < rowPointer + rowptr[i + 1] - rowptr[i]; j++)
        {
            cout << i << " " << column[j];
            cout << endl;
        }
        rowPointer += (rowptr[i + 1] - rowptr[i]);
        // cout<<rowPointer<<endl;
    }

    // Node Iterator on CSR
    // stores the triangle count
    int triangleResult = 0;

    for (int i = 0; i < n; i++)
    {
        int difference = rowptr[i + 1] - rowptr[i];
        if (difference > 0)
        {
            // storing the neighboures of vertex i
            vi Na(difference);
            for (int k = 0; k < difference; k++)
            {
                Na[k] = column[k + rowptr[i]];
            }
            
            vi temp(n);
            // Intializing all values to 0
            for (int k = 0; k < n; k++)
            {
                temp[k] = 0;
            }

            for (int k = 0; k < Na.size(); k++)
            {
                temp[Na[k]] = 1;
            }

            // cout << "\n\nNeighbours of v1[" << i << "]: ";
            // for (int k = 0; k < Na.size(); k++)
            // {
            //     cout << Na[k] << " ";
            // }
            // cout<<"\n--------------------";
            omp_set_num_threads(NUM_THREADS);
            #pragma omp parallel
            {
                #pragma omp for
                // iterating over the neighbours of each vertices
                for (int j = rowptr[i]; j < rowptr[i] + difference; j++)
                {
                    int v2 = column[j];
                    int count = rowptr[v2 + 1] - rowptr[v2]; // number of neighbours of v2
                    if (count > 0)
                    {
                        // storing the neighbours of v2
                        vi Nb;
                        for (int k = rowptr[v2]; k < rowptr[v2] + count; k++)
                        {
                            Nb.push_back(column[k]);
                        }

                        // cout << "\nNeighbours of v2[" << v2 << "]: ";
                        // for (int k = 0; k < Nb.size(); k++)
                        // {
                        //     cout << Nb[k] << " ";
                        // }

                        // checking the intersection of the both the vertices neighbours
                        for (int k = 0; k < Nb.size(); k++)
                        {
                            if (temp[Nb[k]] == 1)
                            {
                                triangleResult++;
                                // cout << endl;
                                // cout << i << " " << v2 << " " << Nb[k];
                            }
                        }
                        Nb.clear();
                    }
                    else
                    {
                        continue;
                    }
                }
            }
            Na.clear();
        }
        else
        {
            continue;
        }
    }

    cout << "\nNumber of triangles in the given graph: " << triangleResult << endl;

    return 0;
}