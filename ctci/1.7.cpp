#include<iostream>
using namespace std;

#define n 5

void rotate(int (&matrix)[n][n]){
  for(int i = 0; i < n/2; i++){
    for(int j = i; j < n - i - 1; j++){
      int aux = matrix[i][j];
      matrix[i][j] = matrix[j][i];
      matrix[j][i] = matrix[n - i -1][n - j - 1];
      matrix[n - i -1][n - j - 1] = matrix[n - j -1][i];
      matrix[n - j - 1][i] = aux;
    }
  }
}

void print(int (&matrix)[n][n]){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}

int main(){

  int matrix[n][n];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){matrix[i][j] = 0;}
  }
  matrix[2][3] = 1;
  print(matrix);
  cout << endl;
  rotate(matrix);
  print(matrix);
  return 0;
}
