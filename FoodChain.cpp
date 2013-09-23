#include<cstdio>

//implementations of disjoing-set                                                                                                              

int par[MAX_N]; //father                                                                                                                       
int rank[MAX_N]; //height of trees   

int N, K;

int T[MAX_N], X[MAX_N], Y[MAX_N];                                                                                                           

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
    if(rank[x] == rank[y]) rank[x]++;                                                          
  }
}

//check if x and y are in the same sef                                                                                                         
bool same(int x, int y){
  return find(x) == find(y);
}

int main(){
  scanf("%d %d %d", &MAX_N, &N, &K);

  //initialize disjoint set
  //element x, x + N, x + 2 * N represents x-A, x-B, x-C
  init(N * 3);
  
  int ans = 0;
  for(int i = 0; i < K; i++){
    int t = T[i];
    int x = X[i] - 1, y = Y[i] - 1;//transfer input into 0, ..., N - 1

    //incorrect number
    if(x < 0 || N <= x || y < 0 || N <= y){
      ans++;
      continue;
    }

    if(t == 1){
      //first kind information
      if(same(x, y + N) || same(x, y + 2 * N)){
	ans++;
      }else{
	unite(x, y);
	unite(x + N, y + N);
	unite(x + N * 2, y + N * 2);
      }
    }else{
      //second kind information
      if(same(x, y) || same(x, y + 2 * N)){
	ans++;
      }else{
	unite(x, y + N);
	unite(x + N, y + N * 2);
	unite(x + M * 2, y);
      }
    }
  }

  printf("%d\n", ans);

  return 0;
}
