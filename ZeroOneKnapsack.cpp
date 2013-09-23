#include<cstdio>

const int MAX_N = 100;

int n, W;
int w[MAX_N], v[MAX_N];

int max(int a, int b){
  if(a > b) return a;
  return b;
}
 

//find the part whose weight is less than j from object i                       
int rec(int i, int j){
  int res;
  if(i == n){
    //nothing left                                                               
    res = 0;
  }else if(j < w[i]){
    //can not select this object                                                 
    res = rec(i + 1, j);
  }else{
    res = max(rec(i + 1, j), rec(i + 1, rec(i + 1, j - w[i]) + v[i]));
  }

  return res;
}

void solve(){
  printf("%d\n", rec(0, W));
}

int main(){
  scanf("%d %d", &n, &W);
  solve();
  return 0;
}

