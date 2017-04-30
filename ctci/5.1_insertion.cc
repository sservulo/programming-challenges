#include<iostream>
using namespace std;

int bitInsert(int n, int m, int i, int j){
  return (((n >> (i+j)) << (i+j)) | (m << i)) | (n & ((1 << i) - 1));
}

int main(){
  cout << bitInsert(1024, 19, 2, 6);
  return 0;
}
