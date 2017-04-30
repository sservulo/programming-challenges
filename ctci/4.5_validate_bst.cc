#include<iostream>
#include<vector>
#include<limits>
using namespace std;

struct Node{
  int value;
  Node* left;
  Node* right;
};

bool isBST(Node* n, int min, int max){
  if(!n){return true;}
  bool validNode = min <= n->value && n->value <= max;
  if(!validNode){return false;}
  return isBST(n->left, min, n->value) && isBST(n->right, n->value+1, max);
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

  graph->at(0)->value = 5;
  graph->at(1)->value = 1;
  graph->at(2)->value = 6;
  graph->at(3)->value = 0;
  graph->at(4)->value = 3;
  graph->at(5)->value = 2;
  graph->at(6)->value = 4;

  graph->at(0)->left = graph->at(1);
  graph->at(0)->right = graph->at(2);

  graph->at(1)->left = graph->at(3);
  graph->at(1)->right = graph->at(4);

  graph->at(4)->left = graph->at(5);
  graph->at(4)->right = graph->at(6);

  //inOrder(graph->at(0));

  return graph;
}

int main(){
  vector<Node*>* graph = getTree();
  cout << isBST(graph->at(0), numeric_limits<int>::min(), numeric_limits<int>::max()) << endl;
  return 0;
}
