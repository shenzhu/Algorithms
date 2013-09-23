int prime[MAX_N];//the ith prime number
bool is_prime[MAX_N + 1];//is_prime[i] is true means i is prime

//return the prime number lower than n
int sieve(int n){
  int p = 0;

  for(int i = 0; i <= n; i++) is_prime[i] = true;
  is_prime[1] = false;//1 and 0 are not prime number 
  is_prime[0] = false;
  
  for(int i = 2; i <= n; i++){
    if(is_prime[i]){
      //prime[p] = i;
      //p++;
      prime[p++] = i;
      for(int j = 2 * i; j <= n; j+= i)
	is_prime[j] = false;
    }
  }

  return p;
}
