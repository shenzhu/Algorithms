// input
int P;// pages
int a[P];

int main(){
	// use set to store all the points
	set<int> all;
	for(int i = 0; i < P; i++){
		all.insert(a[i]);
	}
	int n = all.size();// n is the number of different points

	int s = 0, t = 0, sum = 0;
	map<int, int> count;// stores the number of points 
	int res = P;

	for(;;){
		while(t < P && sum < n){
			if(count[a[t++]]++ == 0){// meets a new point
				num++;
			}
		}

		if(num < n) break;
		res = min(res, t - s);
		if(--count[a[s++]] == 0){
			num--;
		}
	}

	printf("%d\n", res);

	return 0;
}