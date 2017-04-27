#include<iostream>
#include<cmath>
using namespace std;

int maxBitSequence(int num){
  int cCount = 0;
  int nCount = 0;
  int maxCount = 0;
  bool merged = false;
  while(num){
    bool one = (num & 1) == 1;
    num >>= 1;
    if(one && !merged){
      cCount++;
      continue;
    }
    if(one && merged){
      cCount++;
      nCount++;
      merged = true;
      continue;
    }
    if(!one && !merged){
      cCount++;
      merged = true;
      continue;
    }
    if(!one && merged){
      maxCount = max(maxCount, cCount);
      cCount = nCount;
      nCount = 0;
      merged = false;
    }
  }
  return max(cCount, maxCount);
}

int main(){
  cout << maxBitSequence(1775) << endl;
  return 0;
}
