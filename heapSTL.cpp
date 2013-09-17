#include<cstdio>
#include<queue>
using namespace std;

int main(){
  //declare
  priority_queue<int> pque;
  
  //push elements
  pque.push(3);
  pque.push(5);
  pque.push(1);

  //loop until heap is empty
  while(!pque.empty()){
    //print and delete max value
    printf("%d\n", pque.top());
    pque.pop();
  }

  return 0;
}
