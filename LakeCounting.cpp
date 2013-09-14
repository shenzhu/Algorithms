#include<cstdio>

const int MAX_N = 100;
const int MAX_M = 100;
int N, M;
char field[MAX_N][MAX_M+1];//yard

//our position now is (x,y)
void dfs(int x, int y){
  //replace the position to '.'
  field[x][y] = '.';

  //looping through 8 positions around it
  for(int dx = -1; dx <= 1; dx++){
    for(int dy = -1; dy <=1; dy++){
      //move dx in x, move dy in y, the result would be (nx, ny)
      int nx = x + dx, ny = y + dy;
      //check if (nx, ny) is in the yard
      if(0 <= nx && nx < N && 0 <= ny && ny < M && field[nx][ny] == 'W') dfs(nx, ny);
    }
  }
  return;
}

void solve(){
  int res = 0;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      if(field[i][j] == 'W'){
	dfs(i, j);
	res++;
      }
    }
  }
  printf("%d\n", res);
}

int main(){
  scanf("%d %d", &N, &M);
  solve();
  return 0;
}
