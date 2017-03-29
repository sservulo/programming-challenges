#include<iostream>
#include<unordered_map>
using namespace std;

bool isUnique(const string& s){
  if(s.length() > 128) {return false;}

  unordered_map<char,int> hash;
  for(auto c : s){
    if(++hash[c] > 1){return false;}
  }
  return true;
}

 int main(){
    string s = "qwertyuio";
    cout << isUnique(s);
    return 0;
}
