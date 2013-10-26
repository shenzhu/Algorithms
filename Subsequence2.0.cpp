/*
	This problem uses a foot emulated method(not sure about the English translation),
	foot emulated method is a method to get the minimum range by pushing the start and 
	end of the intilial range.
*/
// input
int n, S;
int a[n];

int main(){
	int res = n + 1;
	int s = 0, t = 0, sum = 0;// initialize the values

	for(;;){
		while(t < n && sum < S){
			sum += a[t++];
		}

		if(sum < S) break;

		res = min(res, t - s);
		sum -= a[s++];
	}

	if(res > n){
		// answer does not exist
		res = 0;
	}

	printf("%d\n", res);

	return 0;
}