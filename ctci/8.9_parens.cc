#include<iostream>
#include<unordered_set>
using namespace std;

void swap(string& s, int i, int j){
  char aux = s[i];
  s[i] = s[j];
  s[j] = aux;
}

unordered_set<string> paren(int n){
  unordered_set<string> ret;
  if(n == 1){
    ret.insert("()");
    return ret;
  }
  unordered_set<string> below = paren(n-1);
  for(string s : below){
    s+="()";
    ret.insert(s);
    for(int j  = s.size()-1; j > 1; j--){
      for(int i = j-1; i>0; i--){
        swap(s, i, i-1);
        //cout << s << endl;
        ret.insert(s);
      }
      for(int i = 0; i < j-2; i++){
        swap(s, i, i+1);
        //ret.insert(s);
      }
      swap(s, j, j-1);
    }
  }
}

int main(){
  unordered_set<string> all = paren(10);
  for(string s : all){
    cout << s << endl;
  }
  return 0;
}
