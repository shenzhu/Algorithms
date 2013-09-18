#include<cstdio>
#include<cstring>
///<cstring> contains memset

const int MAX_N = 100;

int n, W;
int w[MAX_N], v[MAX_N];
//memory array
int dp[MAX_N + 1][MAX_N + 1];

int max(int a, int b){
  if(a > b) return a;
  return b;
}

int rec(int i, int j){
  if(dp[i][j] >= 0){
    //we have calculated this, so use the result directly   
    return dp[i][j];
  }

  int res;
  if(i == n){
    res = 0;
  }else if(j < w[i]){
    res = rec(i + 1, j);
  }else{
    res = max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]);
  }

  //record result to array
  return dp[i][j] = res;
}

int main(){
  scanf("%d %d", &n, &W);
  
  //-1 means havn't been calculated, initialize all the array
  //use memset to initialize high dimentional array
  memset(dp, -1, sizeof(dp));
  printf("%d\n", rec(0, W));
  return 0;
}

