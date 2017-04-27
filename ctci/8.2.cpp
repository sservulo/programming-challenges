#include<iostream>
#include<vector>
using namespace std;

enum Direction{unknown, impossible, downM, rightM, target};

Direction getPath(vector<vector<bool> >& maze, vector<vector<Direction> >& path,
   int row, int column, int n){
     if(column < 0 || column >= n || row < 0 || row >= n){
       return impossible;
     }
     if(row == n-1 && column == n-1){
       path[row][column] = target;
       return target;
     }
     Direction getDown = (column+1 < n) && path[row][column+1] == unknown ?
        getPath(maze, path, row, column+1, n) : path[row][column+1];
     Direction getRight = (row+1 < n) && path[row+1][column] == unknown ?
        getPath(maze, path, row+1, column, n) : path[row][column+1];
     if(getDown == impossible && getRight == impossible){
       path[row][column] = impossible;
     }
     else{
       path[row][column] = getDown > getRight ? downM : rightM;
     }
     return path[row][column];
   }

int main(){
  int n = 5;
  vector<vector<bool> > maze;
  vector<vector<Direction> > path;
  for(int i = 0; i < n; i++){
    vector<bool> row(n,false);
    maze.push_back(row);
    vector<Direction> row2(n,unknown);
    path.push_back(row2);
  }
  getPath(maze, path, 0, 0, n);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cout << path[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
