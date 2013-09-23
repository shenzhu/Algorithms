#include<cstdio>
#include<queue>

const int MAX_N = 100;

//input 
int L, P, N;
int A[MAX_N + 1], B[MAX_N + 1];

void solve(){
  //we regard destination as gas station
  A[N] = P;
  B[N] = 0;
  N++;
  
  //use a priority queue
  std::priority_queue<int> que;

  //ans: number of refuel
  //pos: position at present
  //tank: gas left
  int ans = 0, pos = 0, tank = P;

  for(int i = 0; i < N; i++){
    //the distance to go
    int d = A[i] - pos;
    
    //keep refueling until get the next gas station
    while(tank - d < 0){
      if(que.empty()){
	puts("-1");
	return;
      }
      
      tank += que.top();
      que.pop();
      ans++;
    }

    tank = tank - d;
    pos = A[i];
    que.push(B[i]);
  }

  printf("%d\n", ans);
}

int main(){
  scanf("%d %d %d", &N, &L, &P);
  solve();
  return 0;
}
