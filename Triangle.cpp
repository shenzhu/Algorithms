#include<cstdio>

const int MAX_N = 50;
int n, a[MAX_N]; 

int max(int a, int b)
{
  if (a < b) return b;
  return a;
}
     
void solve()
{
  int ans = 0; //answer
  
  //make i<j<k, so the same stick wouldn't be picked again
  for (int i = 0; i < n; i++){
    for (int j = i + 1; j < n; j++){
      for (int k = j + 1; k < n; k++){
	int len = a[i] + a[j] + a[k];//circle of the triangle 
	int ma = max(a[i], max(a[j], a[k]));//the length of the longest line
	int rest = len - ma;//sum of the two shorter lines
	
	if (ma < rest){
	  //it can make a triangle
	  ans = max(ans, len);
	}
      }
    }
  }
  printf("%d\n", ans);//%d: put out a int: \n:change to a newline
}

int main()
{
  //  int n, a[MAX-N];
  
  scanf("%d", &n);
  solve();
  return 0;
}
