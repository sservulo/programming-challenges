#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>

void Quicksort(std::vector<int>& v, size_t start, size_t end){
  if(v.size()<2){return;}
  size_t left = start;
  size_t right = end;
  size_t pivot = (start+end)/2;
  while(left<right){
    while(v[left]<v[pivot]){left++;}
    while(v[right]>v[pivot]){right--;}
    if(left<=right){
      int temp = v[left];
      v[left] = v[right];
      v[right] = temp;
      left++;
      right--;
    }
  }
  if(right>start){Quicksort(v,start,right);}
  if(left<end){Quicksort(v,left,end);}
}

int main(){
  std::vector<int> arr;
  for(int i = 0; i < 10; i++){
    arr.push_back(rand()%10);
  }

  Quicksort(arr, 0, arr.size()-1);
  for(auto element : arr){
    std::cout << element << ' ';
  }
  std::cout << std::endl;
  return 0;
}
