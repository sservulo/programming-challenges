#include<iostream>
using namespace std;

bool oneAway(string s1, string s2);
bool replaceEdit(string s1, string s2);
bool oneEdit(string s1, string s2);

int main(){
  string s1 = "taco";
  string s2 = "tau";
  cout << oneAway(s1, s2);
  return 0;
}

bool oneAway(string s1, string s2){
  if(s1.length() == s2.length()){return replaceEdit(s1, s2);}
  if(s1.length() == s2.length() - 1){return oneEdit(s1,s2);}
  if(s1.length() - 1 == s2.length()){return oneEdit(s2,s1);}

  return false;
}

bool replaceEdit(string s1, string s2){
  for(int i = 0; i < s1.length(); i++){
    if(s1[i] != s2[i]){
      s2[i] = s1[i];
      if(s1 == s2){return true;}
      break;
    }
  }
  return false;
}

bool oneEdit(string s1, string s2){
  for(int i = 0; i < s1.length(); i++){
    if(s1[i] != s2[i]){
      s1.insert(i,1,s2[i]);
      if(s1 == s2){return true;}
      break;
    }
  }
  return false;
}
