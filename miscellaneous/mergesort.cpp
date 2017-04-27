#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>

void Merge(std::vector<int>& v, size_t start, size_t middle, size_t end){
  std::vector<int> v_aux(end-start+1,0);
  size_t idx = 0;
  size_t left = start;
  size_t right = middle+1;
  while(left<=middle && right<=end){
    if(v[left]<v[right]){v_aux[idx++]=v[left++];}
    else{v_aux[idx++]=v[right++];}
  }
  while(left<=middle){v_aux[idx++]=v[left++];}
  while(right<=end){v_aux[idx++]=v[right++];}

  idx = 0;
  for(size_t v_idx=start; v_idx<=end; v_idx++){
    v[v_idx]= v_aux[idx++];
  }
}

void Mergesort(std::vector<int>& v, size_t start, size_t end){
  if(start==end){return;}
  size_t middle = (start+end)/2;
  Mergesort(v, start, middle);
  Mergesort(v, middle+1, end);
  Merge(v, start, middle, end);
}

int main(){
  std::vector<int> arr;
  for(int i = 0; i < 10; i++){
    arr.push_back(rand()%10);
  }
  Mergesort(arr, 0, arr.size()-1);
  for(auto element : arr){
    std::cout << element << ' ';
  }
  std::cout << std::endl;
  return 0;
}
