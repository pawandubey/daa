#include <iostream>

using namespace std;

template<int V>
void floydWarshall(int (&g)[V][V]){
  for(int k=0; k<V; k++){
    for(int i=0; i<V; i++){
      for(int j=0; j<V; j++){
        if(g[i][k] + g[k][j] < g[i][j])
          g[i][j] = g[i][k] + g[k][j];
      }
    }
  }
}

int main(){
  int graph[5][5] = {
    {},
    {},
    {},
    {},
    {}
  }
  return 0;
}
