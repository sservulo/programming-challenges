#include<iostream>
using namespace std;

string doubleToString(double num){
  string s = "";
  while(num > 0){
    if(s.size() >= 32){return "ERROR";}
    num *= 2;
    s += num >= 1 ? "1" : "0";
    num -= num >= 1 ? 1 : 0;
  }
  return s;
}

int main(){
  double num = 0.5;
  cout << doubleToString(num) << endl;
  return 0;
}
