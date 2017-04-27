#include<iostream>
#include<vector>
#include<limits>
using namespace std;

struct Node{
  int value;
  Node* left;
  Node* right;
  Node* parent;
};

Node* getLeftmost(Node* n){
  while(n->left){n = n->left;}
  return n;
}

Node* getSuccessorInternal(Node* n, Node* previous){
  if(!n){return nullptr;}
  if(n->right && n->right != previous){return getLeftmost(n->right);}
  if(n->parent && n->parent->left == n){return n->parent;}

  return getSuccessorInternal(n->parent, n);
}

Node* getSuccessor(Node* n){
  return getSuccessorInternal(n, nullptr);
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
    newNode->parent = nullptr;
    graph->push_back(newNode);
  }

  graph->at(1)->parent = graph->at(0);
  graph->at(2)->parent = graph->at(0);
  graph->at(3)->parent = graph->at(1);
  graph->at(4)->parent = graph->at(1);
  graph->at(5)->parent = graph->at(4);
  graph->at(6)->parent = graph->at(4);

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
  Node* n = getSuccessor(graph->at(2));
  if(n) cout << n->value << endl;
  return 0;
}
