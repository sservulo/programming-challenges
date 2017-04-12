#include<iostream>
using namespace std;

bool oneAway(string s1, string s2);

int main(){
  string s1 = "taco";
  string s2 = "tacbao";
  cout << oneAway(s1, s2);
  return 0;
}

bool oneAway(string first, string second){
  string s1 = first.length() <= second.length() ? first : second;
  string s2 = second.length() >= first.length() ? second : first;

  bool foundDifference = false;
  int i = 0;
  int j = 0;

  while(i < s1.length() && j < s2.length()){
    if(s1[i] != s2[j]){
      if(!foundDifference){foundDifference = true;}
      else{return false;}

      j++;
    }
    else{
      i++;
      j++;
    }
  }

  return true;
}
