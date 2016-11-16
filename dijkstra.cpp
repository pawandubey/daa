#include <iostream>
#include <climits>

using namespace std;

int minDistance(bool spSet[], int dset[], int V){
  int md = INT_MAX, minin;
  for(int i=0; i<V;i++){
    if(!spSet[i] && dset[i] <= md){
      md = dset[i];
      minin = i;
    }
  }
  return minin;
}

template<int V>
void dijkstra(int (&g)[V][V], int src){
  bool spSet[V];
  int dset[V];

  for(int i=0; i<V; i++){
    spSet[i] = false;
    dset[i] = INT_MAX;
  }

  dset[src] = 0;

  for(int i=0; i<V-1; i++){
    int u = minDistance(spSet,dset,V);
    spSet[u] = true;
    for(int v=0; v<V; v++){
      if(g[u][v] && !spSet[v] && dset[u] != INT_MAX && dset[v] > (dset[u] + g[u][v]))
        dset[v] = dset[u] + g[u][v];
    }
  }

  for(int i=0; i<V; i++)
    cout<<dset[i]<<" ";
}

int main(){
    int graph[9][9] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 0, 10, 0, 2, 0, 0},
                      {0, 0, 0, 14, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };

    dijkstra(graph, 0);

    return 0;
}
