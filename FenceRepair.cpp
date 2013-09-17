#include<cstdio>

typedef long long ll;

const int MAX_N = 100;


//input
int N, L[MAX_N];

void swap(int &a, int &b){
  int c = a;
  a = b;
  b = c;
}

void solve(){
  ll ans = 0;

  //loop until the number of fence is 1
  while(N > 1){
    //calculate the shortest and second shortest fence, default 0 and 1   
    int mii1 = 0, mii2 = 1;
    if(L[mii1] > L[mii2]) swap(mii1, mii2); 

    for(int i = 2; i < N; i++){
      if(L[i] < L[mii1]){
	mii2 = mii1;
	mii1 = i;
      }else if(L[i] < L[mii2]){
	mii2 = i;
      }
    }

    //merge two fences
    int t = L[mii1] + L[mii2];
    ans = ans + t;

    if(mii1 == N - 1) swap(mii1, mii2);
    
    L[mii1] = t;
    L[mii2] = L[N - 1];

    N--;
  }

  printf("%lld\n", ans);
}

int main(){
  scanf("%d", &N);
  solve();
  return 0;
}

  

