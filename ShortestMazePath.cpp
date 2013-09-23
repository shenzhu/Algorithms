#include<cstdio>

const int INF = 100000000;//use large data to inialize, it can be used as a flag
const int MAX_N = 100;
const int MAX_M = 100;

//when using pair to express status, we can use typedef to simplify 
typedef pair<int, int> P;

//input
char maze[MAX_N][MAX_M + 1];//stands for the maze
int N, M;
int sx, sy;//starting point
int gx, gy;//ending point

int d[MAX_N][MAX_M];//the shortest distance to someplace

//moving vector
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

//find the shortest distance from (sx, sy) to (gx, gy), if cannot find, default INF
int bfs(){
  //ready to use BFS
  queue<P> que;
  //inialize all the array to INF
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      d[i][j] = INF;
    }
  }
  //add the starting point to the queue, and set the distance to be 0
  que.push(P(sx, sy));
  d[sx, sy] = 0;

  //looping until the length of the queue is 0
  while(que.size()){
    //get element from the top of queue
    P p = que.front();
    que.pop();

    //if the point is ending point, we can put an end to our search
    if(p.first == gx && p.second == gy) break;
    
    //search in four directions 
    for(int i = 0; i < 4; i++){
      int nx = p.first + dx[i];
      int ny = p.second + dy[i];
      
      //judge if the point can be moved to and if it has been visited
      if(0 <= nx && nx < N && 0 <= ny && ny < M && maze[nx][ny] != '#' && d[nx][ny] = INF){
	//add to the queue and set the distance
	que.push(P(nx, ny));
	d[nx][ny] = d[p.first][p.second] + 1;
      }
    }
  }
  return d[gx][gy];
}

void solve(){
  int res = bfs();
  printf("%d\n", res);
}

int main(){
  scanf("%d %d", &N, &M);
  solve();
  return 0;
}

//Learned:1.the use of pair in C++
//        2.the search method in maze-liked problem
//	  3.the key of using BFS is to build a queue, and keep pushing, fronting and poping
 
