#include <iostream>
#include <queue>

using namespace std;

queue<int> q;
bool visited[4];

template<int V>
bool bfs(int (&graph)[V][V], int s){
  q.push(s);
  while(!q.empty()){
    int cur = q.front();
    q.pop();
    if(!visited[cur]){
      cout<<cur<<"\t";
      visited[cur] = true;
      for(int i=0; i<V; i++){
        if(graph[cur][i] == 1)
          q.push(i);
      }
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
  bfs(graph,1);
  return 0;
}
