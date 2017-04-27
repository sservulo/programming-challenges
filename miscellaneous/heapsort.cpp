#include <vector>
#include <iostream>
#include <cmath>

void MaxHeapify(std::vector<int>& v, size_t heap_size, size_t idx){
  size_t l = 2*idx;
  size_t r = 2*idx + 1;
  size_t largest = idx;
  if(l<heap_size && v[l]>v[largest]){largest = l;}
  if(r<heap_size && v[r]>v[largest]){largest = r;}
  if(largest != idx){
    int temp = v[idx];
    v[idx] = v[largest];
    v[largest] = temp;
    MaxHeapify(v, heap_size, largest);
  }
}

void BuildMaxHeap(std::vector<int>& v){
  for(size_t idx = floor(v.size()/2); idx<v.size(); idx--){
    MaxHeapify(v, v.size(), idx);
  }
}

void Heapsort(std::vector<int>& v){
  BuildMaxHeap(v);
  size_t heap_size = v.size();  
  for(size_t idx=heap_size-1; idx>0; idx--){
    int temp = v[idx];
    v[idx] = v[0];
    v[0] = temp;
    heap_size--;
    MaxHeapify(v, heap_size, 0);
  }
}


int main(){
  std::vector<int> arr;
  for(int i = 0; i < 10; i++){
    arr.push_back(rand()%10);
  }
  Heapsort(arr);
  for(auto element : arr){
    std::cout << element << ' ';
  }
  std::cout << std::endl;
  return 0;
}
