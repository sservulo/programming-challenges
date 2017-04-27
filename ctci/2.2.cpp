#include<iostream>
using namespace std;

template <typename T>
struct Node{
  T data;
  Node* next;
};

template <typename T>
Node<T>* kth(Node<T>* head, int k);

int main(){
  Node<int> n;
  n.data = 1;
  Node<int> n2;
  n2.data = 2;
  n2.next = nullptr;
  n.next = &n2;
  Node<int>* result = kth(&n,1);
  cout << result->data << endl;
  return 0;
}

template <typename T>
Node<T>* kth(Node<T>* head, int k){
  Node<T>* slow = head;
  Node<T>* runner = head;

  for(int i = 0; i < k; i++){
    if(!runner){return nullptr;}
    runner = runner->next;
  }

  while(runner->next){
    slow = slow->next;
    runner = runner->next;
  }

  return slow;
}
