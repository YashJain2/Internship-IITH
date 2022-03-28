// This representation takes O(V+2E) for undirected graph, and O(V+E) for directed graph. 
// If the number of edges are increased, then the required space will also be increased.

#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
int countTriangle=0;

void displayAdjList(list<int> adj_list[], int v) {
    vector <int> a;
    vector <int> b;
  for(int i = 0; i<v; i++) {
     cout << i << "---> ";
     list<int> :: iterator it;
     list<int> :: iterator temp1;
     a.clear();
     for(temp1 = adj_list[i].begin();temp1 != adj_list[i].end();temp1++){
            a.push_back(*temp1);
        }
     for(it = adj_list[i].begin(); it != adj_list[i].end(); ++it) {
         //stores the list of neighbours in *it pointer
        cout << *it << "  ";
        
        list<int> :: iterator temp;
        for(temp = adj_list[*it].begin(); temp != adj_list[*it].end();temp++){
            b.push_back(*temp);
        }
    
        // for(int x=0;x<a.size();x++){
        //     cout<<a[x]<<' ';
        // }
        // cout<<endl;

        // for(int x=0;x<b.size();x++){
        //     cout<<b[x]<<' ';
        // }
        // cout<<endl;

        for(int ii=0;ii<b.size();ii++){
            if(b[ii]==i){
                continue;
            }
            else{
                for(int jj=0;jj<a.size();jj++){
                    if(a[jj]==*it){
                        continue;
                    }
                    else{
                        if(a[jj]==b[ii]){
                            // cout<<endl;
                            // cout<<i<<"\t"<<*it<<"\t"<<b[ii]<<"\t"<<a[jj]<<endl;
                            countTriangle++;
                        }
                    }
                }
            }
        }
        b.clear();
     }
     cout << endl;
   }
   cout<<"No of triangles in the given adjaceny list: "<<countTriangle/6;
}

void add_edge(list<int> adj_list[], int u, int v) {   
//add v into the list u, and u into list v
   adj_list[u].push_back(v);
   adj_list[v].push_back(u);
}


int main(){

    int v = 6;      
    //there are 6 vertices in the graph
    //create an array of lists whose size is 6
    list<int> adj_list[v];
    add_edge(adj_list, 0, 4);
    add_edge(adj_list, 0, 3);
    add_edge(adj_list, 1, 2);
    add_edge(adj_list, 1, 4);
    add_edge(adj_list, 1, 5);
    add_edge(adj_list, 2, 3);
    add_edge(adj_list, 2, 5);
    add_edge(adj_list, 5, 3);
    add_edge(adj_list, 5, 4);
    displayAdjList(adj_list, v);

    return 0;
}
