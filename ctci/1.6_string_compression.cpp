#include<iostream>
#include<cstring>
using namespace std;

string compress(string& s){
  if(s.empty()){return "";}

  string ret = "";
  char c = s[0];
  int count = 0;

  for(size_t i = 1; i < s.size(); i++){
    if(c == s[i]){count++;}
    else{
      ret += c + to_string(count);
      c = s[i];
      count = 1;
    }
  }
  ret += c + to_string(count);

  return s.size() <= ret.size() ? s : ret;
}

int main(){
  string s = "abd";
  cout << compress(s) << endl;
  return 0;
}
