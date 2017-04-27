#include<iostream>
#include<vector>
#include<set>
#include<cstdlib>
#include<ctime>
using namespace std;

int getMagicIndex(vector<int> arr, int b, int e){
  if(b > e){return -1;}
  int middle = (b+e)/2;
  if(arr[middle] == middle){return middle;}
  if(arr[middle] > middle){return getMagicIndex(arr, b, middle-1);}
  return getMagicIndex(arr, middle+1, e);
}

int main(){
  set<int> s;
  vector<int> v;
  int n = 60;
  std::srand(std::time(0));
  for(int i = 0; i < n; i++){
    s.insert(rand()%n);
  }
  for(auto i : s){
    v.push_back(i);
  }
  v[3] = 3;
  cout << getMagicIndex(v, 0, v.size()-1) << endl;
  for(auto i : v){
    cout << i << " ";
  }
  cout << endl;
  for(int i = 0; i < n; i++){
    cout << i << " ";
  }
  return 0;
}
