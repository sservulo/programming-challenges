#include<iostream>
#include<set>
using namespace std;

set<set<int> > getPowerSet(set<int>& s){
  set<set<int> > returnSet;
  if(s.empty()){
    set<int> emptySet;
    returnSet.insert(emptySet);
    return returnSet;
  }

  int e = *(s.begin());
  s.erase(s.begin());
  set<set<int> > subsets = getPowerSet(s);
  set<int> s1;
  for(auto& sub : subsets){
    s1 = sub;
    s1.insert(e);
    returnSet.insert(sub);
    returnSet.insert(s1);
  }
  //returnSet.insert(subsets.begin(), subsets.end());
  //subsets.insert(returnSet.begin(), returnSet.end());
  return returnSet;
}

int main(){
  set<int> s;
  int n = 3;
  for(int i = 0; i < n; i++){
    s.insert(i);
  }
  set<set<int> > powerset = getPowerSet(s);
  for(const auto& subset : powerset){
    for(auto i : subset){
      cout << i << " ";
    }
    cout << endl;
  }
  return 0;
}
