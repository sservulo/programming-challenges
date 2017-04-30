#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>

int BinarySearch(std::vector<int>& arr, int value){
  if(arr.empty()){return -1;}
  int start = 0;
  int end = arr.size()-1;
  while(start<end){
    int middle = (start+end)/2;
    if(arr[middle]==value){return middle;}
    if(arr[middle] > value){
      end = middle-1;
    }
    else{
      start = middle+1;
    }
  }

  return -1;
}

int main(){
  std::vector<int> arr;
  for(int i = 0; i < 10; i++){
    arr.push_back(rand()%10);
  }
  sort(arr.begin(),arr.end());
  for(auto element : arr){
    std::cout << element << ' ';
  }
  std::cout << std::endl;
  std::cout << BinarySearch(arr, 7) << std::endl;
  //std::cout << std::binary_search(arr, 7) << std::endl;
  return 0;
}
