#include<iostream>
using namespace std;

int getSize(char* s){
  char* string = s;
  int size = 0;
  while(*string != '\0'){
    size++;
    string++;
  }
  return size;
}

void reverse(char* s){
  int size = getSize(s);
  if(size<=1){return;}
  int idx=0;
  while(idx < size-idx-1){
    char temp = s[idx];
    s[idx] = s[size-idx-1];
    s[size-idx-1] = temp;
    idx++;
  }
}

int main(){
  char s[] = "batata";
  reverse(s);
  cout << s << endl;
  return 0;
}
