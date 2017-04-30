#include<iostream>
using namespace std;

bool isPerfectSquare(int n){
  int a=0;
  int i=1;
  while(a<n){
    a+=i;
    if(a==n){return true;}
    i+=2;
  }
  return false;
}

int main(){
  cout << isPerfectSquare(121) << endl;
  return 0;
}
