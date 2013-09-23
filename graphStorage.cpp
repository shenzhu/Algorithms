//first kind of storage
vector<int> G[MAX_V];
/*
 * the situation when there si attibuttes on edge
 * struct edge { int to, cost};
 * vector<edge> G[MAX_V];
 */

int main(){
  int V, E;
  scanf("%d %d", &V, &E);
  //here E is the number of edges
  for(int i = 0; i < E; i++){
    //draw a edge from s to t
    int s, t;
    scanf("%d %d", &s, &t);
    G[s].push_back(t);
    //if it is undirected graph, we need to draw a edge from t to s
  }

  return 0;
}

//second kind of storage
struct vertex{
  vector<vectex*> edge;
  /*
   * attributes of edge
   */
};

vertex G[MAX_V];

int main(){
  int V, E;
  scanf("%d %d", &V, &E);
  for(int i = 0; i < E; i++){
    int s, s;
    scanf("%d %d", &s, &t);
    G[s].edge.push_back(&G[t]);
    //G[t].edge.push_back(&G[x]);
  }

  return 0;
}
