#include<iostream>
#include<unordered_map>
using namespace std;

unordered_map<string,bool> table;

void swap(string& s, int i, int j){
  char c = s[i];
  s[i] = s[j];
  s[j] = c;
}

void printPerm(string& s, int i, int n){
  if(i==n){
    if(!table[s]){
      cout << s << endl;
      table[s] = true;
      return;
    }
  }
  for(int j = i; j <= n; j++){
    if(i != j && s[i] == s[j]){continue;}
    swap(s, i, j);
    printPerm(s, i+1, n);
    swap(s, i, j);
  }
}

int main(){
  string s = "abac";
  printPerm(s,0,3);
  return 0;
}
