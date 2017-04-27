#include<iostream>
using namespace std;

template <typename T>
struct Node{
  T data;
  Node* next;
};

template <typename T>
void deleteNode(Node<T>* node){
  if(!node || !node->next){return;}
    Node<T>* aux = node->next;
    node->data = aux->data;
    node->next = aux->next;
}

template <typename T>
void print(Node<T>* node){
  while(node){
    cout << node->data << " ";
    node = node->next;
  }
  cout << endl;
}

int main(){
  Node<int> n;
  n.data = 1;
  Node<int> n2;
  n2.data = 2;
  n.next = &n2;
  n2.next = nullptr;
  deleteNode(&n);
  print(&n);
  return 0;
}
