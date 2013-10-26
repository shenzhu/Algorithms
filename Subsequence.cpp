/*
	template <class ForwardIterator, class T>
	ForwardIterator lower_bound(ForwardIterator first, ForwardIterator last,
										const T& val);
	This function returns an iterator pointing to the first element in the range[first,last)
	whcih does not compare less than val.
*/
// input
int n;// length of array 
int S;
int a[n];// array of ints

int sum[n];// the sum of previous numbers

int main(){
	// calculate array sum
	for(int i = 0;i < n;i++){
		// the rational value of array sum starts at index 1,
		// sum[0] is counted when calculating sum, but it does 
		// not matter because later calculation will offset it
		sum[i + 1] = sum[i] + a[i];
	}

	if(sum[n] < S){
		// answer does not exist
		printf("0\n");
		return 0;
	}


	int res = n;
	for(int s = 0;sum[s] + S <= sum[n];s++){
		// use binary search to find the latter value
		int t = lower_bound(sum + s, sum + n, sum[s] + S) - sum;
		res = min(res, t - s);
	}

	printf("%d\n", res);

	return 0;
}