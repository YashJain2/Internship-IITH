// C++ program for Sparse Matrix Representation using Dictionary
#include<bits/stdc++.h>
using namespace std;
// Sparse matrix [4][5]
#define R 4
#define C 5


int main()
{
	
	int Sparse_Matrix[R][C] =
	{
		{0 , 0 , 3 , 0 , 4 },
		{0 , 0 , 5 , 7 , 0 },
		{0 , 0 , 0 , 0 , 0 },
		{0 , 2 , 6 , 0 , 0 }
	};

	/* Declaration of map where first field(pair of
	row and column) represent key and second field represent value */
	map< pair<int,int>, int > new_matrix;

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (Sparse_Matrix[i][j] != 0)
				new_matrix[make_pair(i+1,j+1)] = Sparse_Matrix[i][j] ;

	int c = 0;

	// Iteration over map for the given graph
    
	for (auto i = new_matrix.begin(); i != new_matrix.end(); i++ )
	{
		if (c != i->first.first)
		{
			cout << "row = " << i->first.first << endl ;
			c = i->first.first;
		}
		cout << "column = " << i->first.second <<" ";
		cout << "value = " << i->second << endl;
	}

	return 0;
}
