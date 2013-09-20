//the edge from vertex from to vertex to whose weight is cost
struct edge {
  int from;
  int to;
  int cost;
}

  edge es[MAX_E];

int d[MAX_V];//length of shortest path
int V, E;

//shortest path from vertex s to all the vertexes
void shortest_path(int s){
  for (int i = 0; i < V; i++){
    d[i] = INF;//initialize
  }

  d[s] = 0;

  while(true){
    bool update = false;
    for(int i = 0; i < E; i++){//iterate all the edges
      edge e = es[i];
      if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost){
	d[e.to] = d[e.from] + e.cost;
	update = true;
      }
    }
    if(!update) break;
  }
}
      
	      
