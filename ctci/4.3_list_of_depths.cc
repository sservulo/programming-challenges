#include<iostream>
#include<vector>
#include<queue>
#include<fstream>
using namespace std;

struct Node{
  int value;
  Node* left;
  Node* right;
};

vector<vector<Node* > > getLevels(Node* root){
  vector<vector<Node*> > v;
  if(!root){return v;}

  int level = 0;
  vector<Node*> l;
  v.push_back(l);

  queue<Node*> q;
  q.push(root);
  q.push(nullptr);

  while(!q.empty()){
    Node* n = q.front();
    q.pop();
    if(n){
      v[level].push_back(n);
      if(n->left){q.push(n->left);}
      if(n->right){q.push(n->right);}
    }
    else{
      if(q.front() != nullptr){q.push(nullptr);} //avoid loop after rightmost leaf, afterwhom exists only a nullptr, which causes loop
      level++;
      vector<Node*> l2;
      v.push_back(l2);
    }
  }
  return v;
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
  vector<vector<Node* > > list = getLevels(graph->at(0));
  for(const auto& l : list){
    for(const auto& node : l){
      cout << node->value << " ";
    }
    cout << endl;
  }
  return 0;
}
