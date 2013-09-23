#include<cstdio>
#include<set>
using namespace std;

int main(){
  //delcaration
  set<int> s;
  
  //insert elements
  s.insert(1);
  s.insert(3);
  s.insert(5);

  //find elements
  set<int>::iterator ite;
  
  //initialize iterator ite
  ite = s.find(1);
  if(ite == s.end()) puts("not found");
  else puts("found");//output found
  
  ite = s.find(2);
  if(ite == s.end()) puts("not found");
  else puts("found");//not found

  //delete elements
  s.erase(3);

  //another method of finding elements
  if(s.count(3) != 0) puts("found");
  else puts("not found");

  //iterator all the elements
  for(ite = s.begin(); ite != s.end(); ite++){
    //attention! ite just works as a pointer, if we want to know the element, use * 
    printf("%d\n", *ite);
  }

  return 0;
}
		       

