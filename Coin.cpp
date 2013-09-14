#include<cstdio>

//values of coins 
const int V[6] = {1, 5, 10, 50, 100, 500};

//input
int C[6];
int A;

int min(int a, int b){
  if(a < b) return b;
  else return a;
}

void solve(){
  int ans = 0;
  
  for(int i = 0; i < 6; i++){
    C[i] = 0;
  }

  for(int i = 4; i >= 0; i--){
    int t = min((A / C[i]), C[i]);
    A = A - t * C[i];
    ans = ans + t;
  }
  
  printf("%d\n", ans);
}

int main(){
  scanf("%d", &A);
  solve();
  return 0;
}
    
    
