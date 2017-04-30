#include<iostream>
#include<cmath>
using namespace std;

typedef unsigned char byte;
const int N = 8;

void drawLine(byte screen[N], int width, int x1, int x2, int y){
  y *= width/8;
  for(int i = min(x1, x2)/8 + 1; i < max(x1,x2)/8; i++){
    screen[y + i] = 0xff;
  }
  screen[y + min(x1,x2)/8] |= 1 << ((min(x1,x2)%8 + 1) - 1);
  screen[y + max(x1,x2)/8] |= ~(1 << ((max(x1,x2)%8 + 1) -1));
}

int main(){
  byte screen[N];
  drawLine(screen, 64, 1, 10, 0);
  return 0;
}
