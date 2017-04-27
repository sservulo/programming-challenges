#include<iostream>
using namespace std;

string getTeens(int n){
  string s;
  switch(n){
    case 10: s = "ten "; break;
    case 11: s = "eleven "; break;
    case 12: s = "twelve "; break;
    case 13: s = "thirteen "; break;
    case 14: s = "fourteen "; break;
    case 15: s = "fifteen "; break;
    case 16: s = "sixteen "; break;
    case 17: s = "seventeen "; break;
    case 18: s = "eighteen "; break;
    case 19: s = "nineteen "; break;
  }
  return s;
}

string getTens(int n){
  string s;
  switch(n){
    case 2: s = "twenty "; break;
    case 3: s = "thirty "; break;
    case 4: s = "fourty "; break;
    case 5: s = "fifty "; break;
    case 6: s = "sixty "; break;
    case 7: s = "seventy "; break;
    case 8: s = "eighty "; break;
    case 9: s = "ninety "; break;
  }
  return s;
}

string getDigit(int n){
  string s;
  switch(n){
    case 1: s = "one "; break;
    case 2: s = "two "; break;
    case 3: s = "three "; break;
    case 4: s = "four "; break;
    case 5: s = "five "; break;
    case 6: s = "six "; break;
    case 7: s = "seven "; break;
    case 8: s = "eight "; break;
    case 9: s = "nine "; break;
  }
  return s;
}

string getRank(int n){
  string s;
  switch(n){
    case 1: s = "thousand "; break;
    case 2: s = "million "; break;
    case 3: s = "billion "; break;
    case 4: s = "trillion "; break;
  }
  return s;
}

string englishInt(int n){
  if(n==0){return "zero ";}
  string s;
  int rank = 0;
  if(n<0){
    s="minus ";
    n *= -1;
  }
  while(n>0){
    string c;
    int chunk = n%1000;
    int hundred = chunk/100;
    if(hundred > 0){
      c += getDigit(hundred) + "hundred ";
    }
    int tens = chunk%100;
    if(tens/10 == 1){
      c += getTeens(tens);
    }
    else{
      c += getTens(tens/10);
      c += getDigit(tens%10);
    }
    c += getRank(rank);
    s = c + s;
    rank++;
    n/=1000;
  }
  return s;
}

int main(){
  cout << englishInt(1806) << endl;
  return 0;
}
