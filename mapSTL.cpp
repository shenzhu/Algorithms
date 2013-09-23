#include<cstdio>
#include<map>
#include<string>
using namespace std;

int main(){
  //declare(int as key, const char* as value)
  map<int, const char*> m;

  //insert elememts
  m.insert(make_pair(1, "ONE"));
  m.insert(make_pair(10, "TEN"));
  m[100] = "HUNDRED";

  //find elements
  map<int, const char*>::iterator ite;
  ite = m.find(1);
  puts(ite->second);

  ite = m.find(2);
  if(ite == m.end()) puts("not found");
  else puts(ite->second);

  puts(m[10]);

  //delete elements
  m.erase(10);

  //iterator all the elements
  for(ite = m.begin(); ite != m.end(); ite++){
    printf("%d: %s\n", ite->first, ite->second);
  }
  
  return 0;
}
