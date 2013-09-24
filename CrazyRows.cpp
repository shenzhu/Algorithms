#include<cstdio>

int swap(int &a, int &b){
  int c = a;
  a = b;
  b = c;
}

int main(){
  int N;
  int M[N][N]; //matrix

  int a[N];//the last a in line i

  int res;//result
  
  //input
  scanf("%d", &N);
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      scanf("%d", &M[i][j]);
	}
  }

  for(int i = 0; i < N; i++){
    a[i] = -1;//initialize array a[N] 
    for(int j = 0; j < N; j++){
      if(M[i][j] == 1) a[i] = j;//give array a[N] proper value
    }
  }

  for(int i = 0; i < N; i++){
    int pos = -1;//the line that need to move to line i
    for(int j = 0; j < N; j++){
      if(a[j] <= i){//draw a graph to understand here
	pos = j;
	break;
      }
    }

    //change
    for(int j = pos; j > i; j--){
      swap(a[j], a[j - 1]);//just change the last value
      res++; 
    }
  }

  printf("%d\n", res);
}
