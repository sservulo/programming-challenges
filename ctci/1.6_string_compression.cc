#include<iostream>
#include<cstring>
using std::string;

string Compress(const string& s){
  if (s.empty()) {return "";}

  string retval = "";
  char c = s[0];
  int count = 1;

  for (size_t i = 1; i < s.size(); i++) {
    if (c == s[i]) {count++;}
    else {
      retval += c + std::to_string(count);
      c = s[i];
      count = 1;
    }
  }
  retval += c + std::to_string(count);
  std::cout << retval << std::endl;
  return s.size() <= retval.size() ? s : retval;
}

int main(){
  string s = "abbbbbbbbbbbd";
  std::cout << Compress(s) << std::endl;
  return 0;
}
