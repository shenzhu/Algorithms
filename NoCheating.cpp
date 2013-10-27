/*
	the usage of bipartite_matching and the boost library in C++
*/
const int dx[4] = {-1, -1, 1, 1};
const int dy[4] = {-1, 0, -1, 0};

// input
int M, N;
char seat[M][N];// seats

int main(){
	int num = 0;
	V = M * N;
	for(int y = 0; y < M; y++){
		for(int x = 0; x < N; x++){
			if(seat[x][y] == '.'){
				num++;

				for(int k = 0; k < 4; k++){
					int x2 = x + dx[k];
					int y2 = y + dy[k];
					
					if(0 <= x2 && x2 < N && 0 <= y2 && y2 < M && seat[y2][x2] == '.'){
						add_edge(x * M + y, x2 * M + y2);// the two numbers represent the indexes of seat
					}
				}
			}
		}
	}

	printf("%d\n", num - bipartite_matching());
	return 0;
}