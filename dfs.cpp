#include <iostream>

using namespace std;

bool visited[4];

template<int V>
bool dfs(int (&graph)[V][V], int s){
  cout<<s<<"\t";
  visited[s] = true;
  for(int i=0; i<V; i++){
    if(!visited[i] && graph[s][i]==1){
      dfs(graph, i);
    }
  }
}

int main(){
  int graph[4][4] = {
    {0,1,1,0},
    {1,0,0,1},
    {1,0,0,1},
    {0,1,1,0}
  };
  dfs(graph,1);
  return 0;
}
