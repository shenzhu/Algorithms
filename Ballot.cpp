#include<cstdio>

const int MAX_N = 50;

int main(){
  int n, m, k[MAX_N];

  //input
  scanf("%d %d", &n, &m);
  //read input into an array 
  for (int i = 0; i < n; i++){
    scanf("%d", &k[i]);
  }    

  //a flag to test if their sum is m
  bool f = false;

  //iterater all the possibilities by four loops
  for (int a = 0; a < n; a++){
    for (int b = 0; b < n; b++){
      for (int c = 0; c < n; c++){
	for (int d = 0; d < n; d++){
	  if (k[a] + k[b] + k[c] + k[d] == m){
	    f = true;
	  }
	}
      }
    }
  }
  
  //output 
  if (f) puts("Yes");
  else puts("No");

  return 0;
}
