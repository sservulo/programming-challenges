#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
#include<climits>
using namespace std;

const int N = 8;

bool check(vector<int> game, int row, int col){
  for(int row2 = 0; row2 < N; row2++){
    int col2 = game[row2];
    if(col == col2 ||
      fabs(row - row2) == fabs(col - col2)){return false;}
  }
  return true;
}

void queens(vector<vector<int> >& solutions, vector<int> game, int row){
  if(row == N){
    solutions.push_back(game);
  }
  else{
    for(int i = 0; i < N; i++){
      if(check(game, row, i)){
        game[row] = i;
        queens(solutions, game, row+1);
      }
    }
  }
}

int main(){
    vector<vector<int> > solutions;
    vector<int> game(8,-10);
    queens(solutions, game, 0);
    for(auto& s : solutions){
      for(auto i : s){
        cout << i << " ";
      }
      cout << endl;
    }
    cout << solutions.size() << endl;
    return 0;
}
