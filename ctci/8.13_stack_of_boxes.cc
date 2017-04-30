#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

struct Box{
  int id;
  int h;
  int w;
  int d;

  bool operator<(Box& b) {
        return h < b.h && w < b.w && d < b.d;
  }
};

int f(vector<Box>& vb, unordered_map<int,int>& h, Box b){
  if(h[b.id]!= 0){return h[b.id];}
  int max = 0;
  for(auto& b1 : vb){
    int current = 0;
    if(b1<b){current = f(vb,h,b1);}
    max = current > max ? current : max;
  }
  h[b.id] = max + b.h;
  return h[b.id];
}

int maxHeight(vector<Box>& vb){
  unordered_map<int,int> h;
  int max = 0;
  for(auto& b : vb){
    int bmax = f(vb,h,b);
    max = bmax > max ? bmax : max;
  }
  return max;
}

int main(){
  int n = 10;
  vector<Box> vb;
  for(int i = 0; i < n; i++){
    Box b;
    b.id = i;
    b.h = rand()%n+1;
    b.w = rand()%n+1;
    b.d = rand()%n+1;
    vb.push_back(b);
  }
  cout << maxHeight(vb) << endl;
  for(auto& b : vb){
    cout << b.h << " " << b.w << " " << b.d << endl;
  }
  return 0;
}
