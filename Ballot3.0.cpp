//Hint:First we enum all the values of the sum of k3 and k4, then we use binary search to find the proper value 

#include<cstdio>

const int MAX_N = 100; //it can be larger than 100, just to be simple   
 
int n, m, k[MAX_N];

//the array that stores the sum of k3 and k4, in fact, n(n+1)/2 is OK, but to be convenient we use n*n
int kk[MAX_N * MAX_N];

bool binary_search(int x){
  //the range of x is between kk[l], kk[l+1],... kk[r-1]
  int l = 0, r = n * n;
  while(r - l >= 1){
    int i = (l + r) / 2;
    if(kk[i] == x) return true;
    else if(kk[i] < x) l = i + 1;
    else r = i;
  }
}

void solve(){
  //enum the sum of k3 and k4
  for(int c = 0; c < n; c++){
    for(int d = 0; d < n; d++){
      kk[c * n + d] = k[c] + k[d];//a good way to store the sum organizedly, there are some numbers in the array that are equal 
    }
  }

  //sort the array to carry on binary search
  sort(kk, kk + n * n);
  
  bool f = false;

  for(int a = 0; a < n; a++){
    for(int b = 0; b < n; b++){
      if(binary_search(m - k[a] - k[b])){
	f = true;
      }
    }
  }

  if (f) puts("Yes");
  else puts("No");
}

int main(){
  scanf("%d %d", &n, &m);
  solve();
  return 0;
}
  
