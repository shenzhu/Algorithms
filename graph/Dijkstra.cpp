int cost[MAX_V][MAX_V]; //cost[u][v] stands for the weight of edge(u, v)
int d[MAX_V]; //distance starts from vertex s
bool used[MAX_V]; //nodes have been used
int V; //number of vertexes

//the shortest distance starts from s to all vertexes
void dijkstra(int s){
  fill(d, d + v, INF);
  fill(used, used + V, false);
  d[s] = 0;

  while(true){
    int v = -1;
    //choose a vertex that has the shortest distance from unused vertexes
    for(int u = 0; u < V; u++){
      if(!used[u] && (v == -1 || d[u] < d[v])) v = u;
    }

    if(v == -1) break;
    used[v] = true;

    for(int u = 0; u < V; u++){
      d[u] = min(d[u], d[v] + cost[v][u]);
    }
  }
} 
