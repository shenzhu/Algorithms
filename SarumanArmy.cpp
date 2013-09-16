#include<cstdio>

const int MAX_N = 1000;

int N, R;
int X[MAX_N];

void sort(int arr[], int n){
  int key;
  
  for(int j = 2; j < n; j++){
    key = arr[j];
    //insert arr[j] into the sorted sequence arr[1...j - 1] 
    int i = j - 1;
    while(i > 0 && arr[i] > key){
      arr[i + 1] = arr[i];
      i = i - 1;
    }

    arr[i + 1] = key;
  }
}

void solve(){
  sort(X, N);

  int i = 0, ans = 0;

  while(i < N){
    //s is the left node that hasn't been covered
    int s = X[i++];
    
    while(i < N && X[i] <= s + R) i++;

    int p = X[i - 1];
    
    while(i < N && X[i] <= p + R) i++;

    ans++;
  }

  printf("%d\n", ans);
}

int main(){
  scanf("%d %d ", &N, &R);
  solve();
  return 0;
}

