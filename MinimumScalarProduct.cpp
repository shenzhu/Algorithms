#include<cstdio>

int main(){
  typedef long long ll;

  //input
  int n;
  int v1[n];
  int v2[n];

  scanf("%d", &n);

  for(int i = 0; i < n; i++){
    scanf("%d", &v1[i]);
  }

  for(int i = 0; i < n; i++){
    scanf("%d", &v2[i]);
  }

  sort(v1, v1 + n);
  sort(v2, v2 + n);

  ll ans = 0;

  for(int i = 0; i < n; i++){
    ans = ans + (ll)v1[i] * v[n - 1 - i];
  }

  printf("%lld\n", ans);
}
