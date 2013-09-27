#include<cstdio>

int main(){
  int n, k;
  int a[n];

  //input
  scanf("%d %d", &n, &k);

  for(int i = 0; i < n - 1; i++){
    scanf("%d", a[i]);
  }

  //initialize existing range
  int lb = -1;
  int ub = n;

  //loop until existing range is less or equal to 1
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(a[mid] >= k){
      //if mid satisfies initial condition, the existing range becomes(l1, mid]
      ub = mid;
    }else{
      //if mid does not satisfies initial condition, the existing range becomes(mid, ub]
      lb = mid;
    }
  }

  //this time, lb + 1 = ub;
  printf("%d\n", ub);
}
