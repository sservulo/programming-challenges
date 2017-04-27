#include<iostream>
using namespace std;

int flip(int i){
  int mask = 0xaaaaaaaa;
  int odd = (i & mask) >> 1;
  int even = (i & ~mask) << 1;
  return odd | even;
}

int main(){
  cout << flip(9) << endl;
  return 0;
}
