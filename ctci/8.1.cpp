#include<iostream>
#include<vector>
#include<limits>
using namespace std;

unsigned long long countClimbs(int steps){
  if(steps < 1){return 0;}
  vector<unsigned long long> step(100,0);
  step[0] = 1;
  step[1] = 2;
  step[2] = 3;
  for(int i = 3; i < 100; i++){
    step[i] = step[i-3] + 3 + step[i-2] + 2 + step[i-1] + 1;
  }
  int batata = 0;
  for(auto i : step){

    cout << batata++ << ": " << i << endl;
  }
  return step[99];
}

int main(){
  cout << numeric_limits<unsigned long long>::max() << endl << endl;
  bool cond = numeric_limits<long long>::max() > countClimbs(100);
  cout << cond << endl;
  return 0;
}
