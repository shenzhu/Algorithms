//the implementations of basic heap operations: push and pop

int heap[MAX_N], sz = 0;
//push
void push(int x){
  //number of node
  int i = sz++;

  while(i > 0){
    //number of father node
    int p = (i - 1) / 2;
    
    //if there is no reverse, we can exit
    if(heap[p] <= x) break;

    //change the values of father node and self
    heap[i] = heap[p];
    //regard the father node as a new pushed node, compare its value with its fatehr value
    i = p;
  }

  heap[i] = x;
}

int pop(){
  //min value
  int ret = heap[0];

  //the value that moves to root
  int x = heap[--sz];
  
  //exchange from root
  int i = 0;
  while(i * 2 + 1 < sz){
    //compare the value of son
    int a = i * 2 + 1;
    int b = i * 2 + 2;
    if(b < sz && heap[b] < heap[a]) a = b;

    //if there is no reverse we can exit
    if(heap[a] >= x) break;

    //boost the value of son
    heap[i] = heap[a];
    i = a;
  }

  heap[i] = x;
  
  return ret;
}
 
    
