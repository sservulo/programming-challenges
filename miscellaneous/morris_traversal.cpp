#include<iostream>
#include<vector>
using namespace std;

struct Node{
  int data;
  Node* left;
  Node* right;
};

Node* getPredecessor(Node* n){
  Node* predecessor = n->left;
  while(predecessor && predecessor->right){predecessor = predecessor->right;}
  return predecessor;
}

void morrisTraversal(Node* n){
  while(n){
    if(!n->left){
      cout << n->data << " ";
      n = n->right;
    }
    else{
      Node* predecessor = getPredecessor(n);
      predecessor->right = n;
      Node* left = n->left;
      n->left = nullptr;
      n = left;
    }
  }
}

vector<Node*> getTree(){
  int n = 7;
  vector<Node*> graph;
  for(int i = 0; i < n; i++){
    Node* newNode = new Node;
    newNode->data = i;
    newNode->left = nullptr;
    newNode->right = nullptr;
    graph.push_back(newNode);
  }

  graph.at(0)->left = graph.at(1);
  graph.at(0)->right = graph.at(2);

  graph.at(1)->left = graph.at(3);
  graph.at(1)->right = graph.at(4);

  graph.at(4)->left = graph.at(5);
  graph.at(4)->right = graph.at(6);

  return graph;
}

int main(){
  vector<Node*> graph = getTree();
  morrisTraversal(graph.at(0));
  return 0;
}
