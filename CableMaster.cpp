/*
	the rope whose length is L can be divided into floor(L/x) ropes with the length of x
*/

int N;//num of ropes
int K;//the target num of ropes
double L[N];//the length of ropes

//check if the conditions are satified
bool C(double x){
	int num = 0;//stores the number of ropes can be cut into with the length of x

	for(int i = 0; i < N; i++){
		num = num + (int)(L[i] / x);//converting float to int has the same function as floor()
	}

	return num >= K;
}

void solve(){
	//intialize the range of solution
	double lb = 0, ub = INF;//regard INF as a very large number, but it is not infinite

	//loop until range of solution is small enough
	for(int i = 0; i < 100; i++){
		double mid = (lb + ub) / 2;
		
		if(C(mid)) lb = mid;
		else ub = mid;
	}

	printf("%.2f\n", floor(ub * 100) / 100);
}