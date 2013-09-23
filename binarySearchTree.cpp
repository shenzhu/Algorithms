//inplementations of binary search tree
//the struct that stands for node
struct node{
  int val;
  node *lch, *rch;
};

//insert node x
//p points to the root
node *insert(node *p, int x){
  //the tree is empty, then create the node
  if(p == NULL){
    node *q = new node;
    q->val = x;
    q->lch = q->rch = NULL;
    return q;
  }else{
    //recursively call insert function
    if(x < p->val) p->lch = insert(p->lch, x);
    else p->rch = insert(p-rch, x);
    //here returns the hole tree 
    return p;
  }
}
      
//find x
bool find(node *p, int x){
  if(P == NULL) return false;
  else if(x == p->val) return true;
  else if(x < p->val) return find(p->lch, x);
  else return find(p->rch, x);
}

//delete x;
node *remove(node *p, int x){
  if(p == NULL) return NULL;
  else if(x < p->val) p->lch = remove(p->lch, x);
  else if(x > p->val) p->rch = remove(p->rch, x);
  else if(p->lch == NULL){
    node *q = p->rch;
    delete p;
    return q;
  }else if(p->lch->rch == NULL){
    node *q = p->lch;
    q->rch = p->rch;
    delete p;
    return q;
  }else{
    node *q;
    for(q = p->lch; q->rch->rch != NULL; q = q->rch);
    node *r = q->rch;
    q->rch = r->lch;
    r->lch = p->lch;
    r->rch = p->rch;
    delete p;
    return r;
  }
  return p;
}
