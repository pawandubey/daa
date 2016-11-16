#include <iostream>
#include <climits>

using namespace std;

//template<int V>
int minkey(int key[], bool mstSet[], int V){
  int min = INT_MAX, minin;

  for(int i=0; i<V; i++){
    if(!mstSet[i] && key[i] < min){
      min = key[i];
      minin = i;
    }
  }
  return minin;
}

template<int V>
void prims(int (&g)[V][V]){
  int parent[V];
  int key[V];
  bool mstSet[V];

  for(int i=0; i<V; i++){
    key[i] = INT_MAX;
    mstSet[i] = false;
  }

  key[0] = 0;
  parent[0] = -1;

  for(int i=0; i<V-1; i++){
    int u = minkey(key, mstSet, V);
    mstSet[u] = true;
    for(int v=0; v<V; v++){
      if(g[u][v] && !mstSet[v] && g[u][v] < key[v]){
        parent[v] = u;
        key[v] = g[u][v];
      }
    }
  }

  for(int i=0; i<V; i++)
    cout<<parent[i]<<" ";
  cout<<endl;
}

int main(){
  int graph[5][5] = {{0, 2, 0, 6, 0},
             {2, 0, 3, 8, 5},
             {0, 3, 0, 0, 7},
             {6, 8, 0, 0, 9},
             {0, 5, 7, 9, 0},
            };
  prims(graph);
  return 0;
}
