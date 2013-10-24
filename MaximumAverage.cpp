// input
int n;// the number of items
int k;
int w[n];// the weights of items
int v[n];// the values of items

double y[n];// v - x * w, it is a new standard for choosing items

// check the conditions
bool C(double x){
	for(int i = 0;i < n;i++){
		y[i] = v[i] - x * w[i];// create a new array storing the new standards
	}

	sort(y, y + n);

	// calculate the sum of top-k numbers in array y
	double sum = 0;
	for(int i = 0;i < k;i++){
		sum += y[n - i - 1];
	}

	return sum >= 0;
}

// use binary searcch to find answer from a wide range
void solve(){
	double lb = 0;
	double ub = INF;// INF is a large value which can be calculated

	for(int i = 0;i < 100;i++){// iterater 100 times to get the value
		double mid = (lb + ub) / 2;
		if(C(mid)) lb = mid;
		else ub = mid;
	}

	printf("%.2f\n", ub);
}

