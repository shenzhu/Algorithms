#include<cstdio>

const int MAX_N = 50;
int a[MAX_N];
int n, k;

//we've got the sum of former i, making branch for item behind i
bool dfs(int i, int sum){
  //if we have computed former n items, then check if sum is euqal to k
  if(i == n) return sum == k;

  //the situation that does not plus a[i]
  if(dfs(i + 1, sum)) return true;

  //the situation that pluses a[i]
  if(dfs(i + 1, sum + a[i])) return true;
  
  //if we can not make k
  return false;
}

void solve(){
  if(dfs(0, 0)) printf("Yes\n");
  else printf("No\n");
}
   
int main(){
  scanf("%d %d", &n, &k);
  solve();
  return 0;
}
