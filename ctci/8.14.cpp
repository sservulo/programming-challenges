#include<iostream>
using namespace std;

pair<int,int> boolEval(string& s, int start, int end){
  if(start==end && s[start]=='0'){return make_pair(0,1);}
  if(start==end && s[start]=='1'){return make_pair(1,0);}
  int evalTrue = 0;
  int evalFalse = 0;
  for(int i = start+1; i < end; i++){
    if(s[i]=='&' | s[i]=='|' | s[i]=='^'){
      pair<int,int> left = boolEval(s,start,i-1);
      pair<int,int> right = boolEval(s,i+1,end);
      if(s[i]=='&'){
        evalTrue+= left.first*right.first;
        evalFalse+= left.first*right.second + left.second*(right.first+right.second);
      }
      if(s[i]=='|'){
        evalTrue+= left.first*(right.first+right.second) + left.second*right.first;
        evalFalse+= left.second*right.second;
      }
      if(s[i]=='^'){
        evalTrue+=left.first*right.second + left.second*right.first;
        evalFalse+=left.first*right.first + left.second*right.second;
      }
    }
  }
  return make_pair(evalTrue,evalFalse);
}

int main(){
  string s = "0&0&0&1^1|0";
  pair<int,int> result = boolEval(s,0,s.size()-1);
  cout << result.first << " " << result.second << endl;
  return 0;
}
