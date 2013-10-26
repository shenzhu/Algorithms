/*
	binary search and greedy algorhtim

	sort the cow houses
	set the first cow to x0
	if the ith cow is set to xj, the for (i+1)th cow, xj+d<=xk
*/

int N;//num of cow houses
int M;//num of cows
int x[N];//positions of cow houses

//check if the condition is satisfied
bool C(int d){
	int last = 0;//the base position

	for(int i = 1; i < M; i++){//iterate over all the cows
		int crt = last + 1;//crt is the current cursor                                                   

		while(crt < N && x[crt] - x[last] < d){
			crt++;
		}

		if(crt == N) return false;//if can not find any position to put cow with the distance of d
		last = crt;
	}
	return true;
}

int solve(){
	//sort the arrary
	sort(x, x + N);

	//binary search from a wide range to find a d
	int lb = 0;
	int ub = 1000;//set ub to be a very large number

	while(ub - lb > 1){
		int mid = (ub + lb) / 2;
		if C(mid) lb = mid;
		else ub = mid;
	}

	printf("%d\n", lb);
}