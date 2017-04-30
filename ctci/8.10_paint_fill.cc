#include<iostream>
#include<vector>
using namespace std;

enum Color{black, red, blue};

void fill(vector<vector<Color> >& matrix, int i, int j, Color prev, Color target){
  int n = matrix.size();
  if(i < 0 || i >= n || j < 0 || j >= n){return;}
  if(prev == target){return;}
  if(matrix[i][j] != prev){return;}
  matrix[i][j] = target;
  fill(matrix,i-1,j,prev,target);
  fill(matrix,i+1,j,prev,target);
  fill(matrix,i,j-1,prev,target);
  fill(matrix,i,j+1,prev,target);
}

int main(){
  vector<vector<Color> > matrix;
  int n=10;
  for(int i=0; i<n;i++){
    vector<Color> column(n,black);
    matrix.push_back(column);
  }
  for(int i=0; i<n; i++){
    matrix[i][3] = blue;
  }
  fill(matrix,3,4,black,red);
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
