#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

vector<int> merge(vector<int> a, vector<int> b){
  if(b.empty()){return a;}
  if(a.empty()){return b;}
  int newAI = a.size()-1;
  int bI = b.size()-1;
  int oldAI = a.size() - b.size()-1;
  cout << a[oldAI] << endl;
  while(bI >= 0){
    if(b[bI]>a[oldAI]){
      a[newAI] = b[bI];
      bI--;
    }
    else{
      a[newAI] = a[oldAI];
      oldAI--;
    }
    newAI--;
  }
  return a;
}

void print(vector<int>& a){
  for(auto i : a){
    cout << i << " ";
  }
  cout << endl;
}

int main(){
  vector<int> a = {1, 4, 5, 8, 11, 17, 29, 0, 0, 0};
  vector<int> b = {2,13,42};
  print(a);
  print(b);
  a = merge(a,b);
  print(a);
  return 0;
}
