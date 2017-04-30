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

int main(){
  cout << bitCount(11);
  return 0;
}
