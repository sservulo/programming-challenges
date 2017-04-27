#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

struct Node{
  int value;
  Node* leftTree;
  Node* rightTree;
};

Node* createBinaryTree(const vector<int>& v, int i, int j){
  if(i > j){return nullptr;}
  Node* newNode = new Node;
  newNode->value = v[(i+j)/2];
  newNode->leftTree = createBinaryTree(v, i, (i+j)/2 - 1);
  newNode->rightTree = createBinaryTree(v, (i+j)/2 + 1, j);
  return newNode;
}

void inOrder(const Node* node){
  if(!node){return;}
  inOrder(node->leftTree);
  cout << node->value << " ";
  inOrder(node->rightTree);
}

int main(){
  vector<int> v;
  set<int> s;
  for(int i = 0; i < 20; i++){
    int data = rand()%20;
    s.insert(data);
  }
  for(auto i : s){
    v.push_back(i);
  }
  //cout << endl;
  //sort(v.begin(), v.end());
  for(auto i : v){
    cout << i << " ";
  }
  cout << endl;
  Node* n = createBinaryTree(v, 0, v.size()-1);
  if(n) inOrder(n);
  //cout << n->value;
  return 0;
}
