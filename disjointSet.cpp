 
//implementations of disjoing-set

int par[MAX_N]; //father
int rank[MAX_N]; //height of trees

//initialzie n elements
void init(int n){
  for(int i = 0; i < n; i++){
    par[i] = i;
    rank[i] = 0;
  }
}

//search for the root of tree
int find(int x){
  if(par[x] == x){
    return x;
  }else{
    return par[x] = find(par[x]);//search upwards level by level
  }
}
 

//unite the sets that x and y belongs
void unite(int x, int y){
  //x and y belongs to the same set 
  par[x] = find(x);
  par[y] = find(y);
  if(x == y) return;

  if(rank[x] < rank[y]){
    par[x] = y;
  }else{
    par[y] = x;
    //if they have the same height, level up x, x is just the root the original x belongs 
    if(rank[x] == rank[y]) rank[x]++;
  }
}

//check if x and y are in the same set
bool same(int x, int y){
  return find(x) == find(y);
} 
