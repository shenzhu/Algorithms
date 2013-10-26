const int MOD = 1000;

typedef vector<int> vec;
typedef vector<vec> matl

//input
int n;

int main(){
  mat A(2, vec(2, 0));

  //initialize matrix
  A[0][0] = 3;
  A[0][1] = 5;
  A[1][0] = 1;
  A[1][1] = 3;

  A = pow(A, n);

  printf("%03d\n", (A[0][0] * 2 + MOD - 1) % MOD);

  return 0;
}
