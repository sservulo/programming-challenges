#include<iostream>
using namespace std;

struct Node{
  int data;
  Node* next;
};

Node* reverseIterative(Node* root){
  if(!root){return nullptr;}
  stack<Node*> s;
  Node* n = root;
  while(n){
    s.push(n);
    n = n->next;
  }
  Node* newRoot = s.top();
  s.pop();
  n = newRoot;
  while(!s.empty()){
    n->next = s.top();
    n = n->next;
    s.pop();
  }
  n->next = nullptr;
  return newRoot;
}


Node* reverseRecursive(Node* root){
  if(!root){return nullptr;}
  if(!root->next){return root;}
  Node* newRoot = reverse(root->next);
  root->next->next = root;
  root->next = nullptr;
  return newRoot;
}

void print(const Node* n){
  while(n){
    cout << n->data << " ";
    n = n->next;
  }
  cout << endl;
}

int main(){
  Node* root = new Node();
  root->data = 0;
  root->next = nullptr;
  Node* n = root;
  for(int i=1; i<10; i++){
    n->next = new Node();
    n = n->next;
    n->data = i;
    n->next = nullptr;
  }
  print(root);
  root = reverseIterative(root);
  print(root);
  return 0;
}
