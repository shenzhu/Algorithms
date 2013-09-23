#include<cstdio>
#include<vector>

//input
int V;
int MAX_V;

vector<int> G[MAX_V];

int color[MAX_V];//color of vertexes, to be or not to be

//color the vertexes to 1 or -1
bool dfs(int v, int c){
  color[v] = c;//color vertex v to c
  for(int i = 0; i < G[v].size(); i++){
    if(color[G[v][i]] == c) return false;
    if(color[G[v][i]] == 0 && !dfs([G[v][i]], -c)) return false;
  }
  
  return 0;
}

int main(){
  for(int i = 0; i < V; i++){
    if(color[i] == 0){
      if(!dfs(i, 1)){
	printf("No\n");
	return 0;
      }
    }
  }

  printf("Yes\n");
  return 0;
}
