#include<cstdio>

const int MAX_N = 2000;

int N;
char S[MAX_N];

void solve(){
  //the remaing char array is S[a], S[a + 1], S[a + 2],...S[b]
  int a = 0, b = N - 1;

  while(a <= b){
    //compare char from start and end of array
    bool left = false;
    
    for(int i = 0; a + i <= b; i++){
      if(S[a + i] < S[b - i]){
	left = true;
	break;
      }else if(S[a + i] > S[b - i]){
	  left = false;
	  break;
	}
    }

    if(left) putchar(S[a++]);
    else putchar(S[b--]);
  }

  putchar('\n');
}

int main(){
  scanf("%d", &N);
  solve();
  return 0;
}


	
