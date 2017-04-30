#include<iostream>
using namespace std;

int bitCount(int i){
  int count = 0;
  while(i){
    count++;
    i &= i-1;
  }
  return count;
}

int hammingDistance(int i, int j){
  return bitCount(i^j);
}

int main(){
  cout << hammingDistance(1, 2);
  return 0;
}
