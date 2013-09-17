#include<cstdio>
#include<queue>

typedef long long ll;

const int MAX_N = 100;

int N;
int L[MAX_N];

void solve(){
  ll ans = 0;

  //declare a priority queue
  priority_queue<int, vector<int>, greater<int> >  que; 
  for(int i = 0; i < N; i++){
    que.push(L[i]);
  }

  //loop until there is only one plank left
  while(que.size() > 1){
    //take the shortest and second shortest planks
    int l1, l2;
    l1 = que.top();
    que.pop();
    l2 = que.top();
    que.pop();
    
    //merge thw planks
    ans += l1 + l2;
    que.push(l1 + l2);
  }

  printf("%lld\n", ans);
}

int main(){
  scanf("%d", &N);
  solve();
  return 0;
}
