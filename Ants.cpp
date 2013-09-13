//Hint: The meet of ants does not make any difference, so we can just count the distance as time

#include<cstdio>

const int MAX_N = 100; 

int L, n;
int x[MAX_N];

int max(int a, int b){
  if (a < b) return b;
  return a;
}

int min(int a, int b){
  if (a < b) return a;
  return b;
}

void solve(){
  //compute the shortest time
  int minT = 0;
  for(int i = 0; i < n; i++){
    minT = min(minT, min(x[i], L - x[i]));
  }

  //compute the longest time
  int maxT = 0;
  for(int i = 0; i < n; i++){
    maxT = max(maxT, max(x[i], L - x[i]));
  }

  printf("%d %d\n", minT, maxT);
}

int main(){
  
  scanf("%d %d", &L, &n);
  
  solve();
  return 0;
}
