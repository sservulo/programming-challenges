#include<iostream>
#include<vector>
using namespace std;

struct Node{
  int value;
  Node* left;
  Node* right;
};

void DFS(Node* n, vector<vector<Node*> >& v, int level){
  if(level >= v.size()){
    vector<Node*> l;
    v.push_back(l);
  }
  v[level].push_back(n);
  if(n->left){DFS(n->left, v, level + 1);}
  if(n->right){DFS(n->right, v, level + 1);}
}

void printLevels(Node* n){
  if(!n){return;}
  vector<vector<Node*> > v;
  DFS(n, v, 0);
  for(const auto& level : v){
    for(const auto& n : level){
      cout << n->value << " ";
    }
    cout << endl;
  }
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
  graph->at(0)->right = graph->at(2);

  graph->at(1)->left = graph->at(3);
  graph->at(1)->right = graph->at(4);

  graph->at(4)->left = graph->at(5);
  graph->at(4)->right = graph->at(6);

  inOrder(graph->at(0));

  return graph;
}

int main(){
  vector<Node*>* graph = getTree();
  printLevels(graph->at(0));
  return 0;
}
