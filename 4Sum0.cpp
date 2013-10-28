// input
int n;
int A[n], B[n], C[n], D[n];

int CD[n * n];// number of combinations of C and D

int main(){
	// enumerate the combinations of C and D
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int cd = -(A[i] + B[j]);

			res += upper_bound(CD, CD + n * n, cd) - lower_bound(CD, CD + n * n, cd);
		}
	}

	printf("&lld\n", res);
	return 0;
}