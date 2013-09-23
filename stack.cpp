#include<stack>
#include<cstdio>

using namespace std;

int main(){
  stack<int> s; //declare the stack stores int
  s.push(1);
  s.push(2);
  s.push(3);
  printf("%d\n", s.top());
  s.pop();
  printf("%d\n", s.top());
  s.pop();
  printf("%d\n", s.top());
  s.pop();
  return 0;
}
