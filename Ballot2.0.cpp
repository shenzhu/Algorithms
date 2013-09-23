//We can use k4 = m - k1 - k2 - k3 to compute k4 first, and then use binary search to see if there is a proper value in the array
#include<cstdio>

const int MAX_N = 100;
int n, m, k[MAX_N];

bool binary_search(int x){
  //the range of x is k[l], k[l+1], ...k[r-1]
  int l = 0, r = n;
  
  //repeat the following until the range is empty
  while(r - 1 >= 1){
    int i = (l + r) / 2;//compute the middle
    if(k[i] == x) return true;
    else if(k[i] < x) l = i + 1;
    else r = i;
  }

  //does not find x
  return false;
}

void solve(){
  //to carry out binary search we need to sort first
  sort(k, k + n);
  
  //a flag to test if we can find proper value, defalut false
  bool f = false;

  for(int a = 0; a < n; a++){
    for(int b = 0; b < n; b++){
      for(int c = 0; c < n; c++){
	//change the inner loop to binary search
	if(binary_search(m - k[a] - k[b] - k[c])) 
	  f = true;
      }
    }
  }
  
  if(f) puts("Yes");
  else puts("No");
}

      

int main(){
  scanf("%d %d", &n,&m);
  solve();
  return 0;
} 
