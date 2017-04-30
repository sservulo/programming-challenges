#include<iostream>
using namespace std;

int recursiveMul(int a, int b){
  int smaller = a < b ? a : b;
  int bigger = b > a ? b : a;
  if(smaller == 0){return 0;}
  if(smaller == 1){return a;}
  if(smaller % 2 == 1){return bigger + recursiveMul(bigger, smaller-1);}
  return recursiveMul(bigger<<1, smaller>>1);
}

int main(){
  cout << recursiveMul(13,5);
  return 0;
}
