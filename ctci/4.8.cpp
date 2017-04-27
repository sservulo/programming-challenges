#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

struct Node{
  int value;
  bool built;
  Node* left;
  Node* right;
};

Node* getAncestor(Node* n, Node* p, Node* q){
  if(!n || !p || !q){throw 0;}

  Node* left = nullptr;
  Node* right = nullptr;
  if(n->left){left = getAncestor(n->left, p, q);}
  if(n->right){right = getAncestor(n->right, p, q);}

  if((left && right) ||
    ((left || right) && (n == p || n == q))){return n;}
  if(left){return left;}
  if(right){return right;}
  if(n == p || n == q){return n;}

  return nullptr;
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
  Node* n = getAncestor(graph->at(0), graph->at(0), graph->at(5));
  cout << n->value;
  return 0;
}
