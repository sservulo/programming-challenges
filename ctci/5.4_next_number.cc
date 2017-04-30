#include<iostream>
using namespace std;

void printSwap(int num, int one, int zero){
  num |= (1 << zero);
  num &= ~(1 << one);
  cout << num << endl;
}

void printNext(int num){
  int lowestZero = -1;
  int lowestOne = -1;
  int biggestZero = -1;
  int biggestOne = -1;
  int numcopy = num;
  for(int i = 0; i < 31; i++){
    bool one = (numcopy & 1) == 1;
    numcopy >>= 1;
    if(one){
      if(lowestOne == -1){lowestOne = i;}
      biggestOne = i;
    }
    else{
      if(lowestZero == -1){lowestZero = i;}
      biggestZero = i;
    }
  }
  if(lowestOne == -1 || lowestZero == -1){return;}
  printSwap(num, biggestOne, lowestZero);
  printSwap(num, lowestOne, biggestZero);
}

int main(){
  printNext(2);
  return 0;
}
