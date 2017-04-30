#include<iostream>
#include<vector>
using namespace std;

class Bitvector{
  vector<long> v;
  public:
    explicit Bitvector(size_t size);
    void set(int n);
    bool get(int n);
};

Bitvector::Bitvector(size_t size){
  v = vector<long>(size/64+1,0);
}

void Bitvector::set(int n){
  v[n>>6] |= 1 << (n%64);
}

bool Bitvector::get(int n){
  return (bool)((v[n>>6]>>(n%64))&1);
}

int main(){
  Bitvector bv(10);
  bv.set(7);
  for(int i=0; i<100000;i++){
    cout << i << " " << bv.get(i) << endl;
  }
  return 0;
}
