#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

struct Node{
  int value;
  Node* left;
  Node* right;
};

int getHeight(Node* n){
  if(!n){return 0;}

  int leftTreeHeight = getHeight(n->left);
  int rightTreeHeight = getHeight(n->right);

  if(leftTreeHeight == -1 || rightTreeHeight == -1 ||
    fabs(leftTreeHeight - rightTreeHeight) > 1){return -1;}

  int maxHeight = leftTreeHeight >= rightTreeHeight ? leftTreeHeight : rightTreeHeight;

  return maxHeight + 1;
}

bool isBalanced(Node* root){
  return getHeight(root) != -1;
}

void inOrder(const Node* node){
  if(!node){return;}
  inOrder(node->left);
  cout << node->value << endl;
  inOrder(node->right);
}

vector<Node*>* getTree(){
  int n = 7;
  vector<Node*>* graph = new vector<Node*>();
  for(int i = 0; i < n; i++){
    Node* newNode = new Node;
    newNode->value = i;
    newNode->left = nullptr;
    newNode->right = nullptr;
    graph->push_back(newNode);
  }

  graph->at(0)->left = graph->at(1);
  //graph->at(0)->right = graph->at(2);

  graph->at(1)->left = graph->at(3);
  graph->at(1)->right = graph->at(4);

  // graph->at(4)->left = graph->at(5);
  // graph->at(4)->right = graph->at(6);

  //inOrder(graph->at(0));

  return graph;
}

int main(){
  vector<Node*>* graph = getTree();
  cout << isBalanced(graph->at(0)) << endl;
  return 0;
}
