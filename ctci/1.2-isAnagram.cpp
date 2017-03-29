#include<iostream>
#include<unordered_map>
using namespace std;

bool isAnagram(const string& s1, const string& s2){
  if(s1.length() != s2.length()){return false;}

  unordered_map<char,int> hash;
  for(auto c : s1){
    hash[c]++;
  }
  for(auto c: s2){
    hash[c]--;
  }
  for(const auto& iterator : hash){
    if(iterator.second != 0){return false;}
  }
  return true;
}

 int main(){
    string s1 = "potato";
    string s2 = "";
    cout << isAnagram(s1,s2);
    return 0;
}
