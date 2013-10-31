// input
int N;// number of stocks
int K;// number of time nodes
int P[N][K];

int main(){
	V = N * 2;
	for(int i = 0; i < V; i++)
		G[i].clear();

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(i == j) continue;

			bool f = true;
			for(int k = 0; k < K; k++){
				if(P[j][k] >= P[i][k]) f = false;
			}

			if(f) add_edge(i, N + j);
		}
	}

	int ans = N - bipartite_matching();
	printf("%d\n", ans);

	return 0;
}