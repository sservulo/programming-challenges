#include<iostream>
#include<vector>
using namespace std;

int getLocation(vector<string>& v, string s){
  int start=0;
  int end=v.size()-1;
  while(start<=end){
    int middle=(start+end)/2;
    if(v[middle].empty()){
      int left=middle-1;
      int right=middle+1;
      while(true){
        if(left<start && right>end){
          return -1;
        }
        if(left>=start && !v[left].empty()){
          middle=left;
          break;
        }
        if(right<=end && !v[right].empty()){
          middle=right;
          break;
        }
        left--;
        right++;
      }
    }
    if(v[middle]==s){return middle;}
    if(v[middle]>s){end=middle-1;}
    else{start=middle+1;}
  }
  return -1;
}

int main(){
  vector<string> v = {"at","","","","ball","","","car","","","dad","",""};
  cout << getLocation(v,"dad") << endl;

  return 0;
}
