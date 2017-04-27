#include<iostream>
using namespace std;

template<typename T>
struct Node{
  T data;
  Node* next;
};

template <typename T>
void print(const Node<T>& node);
template <typename T>
Node<T>* partition(Node<T>* head, int x);

int main(){

  Node<int>* head;
  Node<int>* last;
  for(int i = 0; i < 10; i++){
    Node<int>* n = new Node<int>;
    n->data = i;
    if(i%2 == 0){n->data = 0;}
    n->next = nullptr;
    if(i == 0){
      head = n;
    }
    else{
      last-> next = n;
    }
    last = n;
  }
  print(*head);
  head = partition(head, 1);
  print(*head);

  return 0;
}

template <typename T>
void print(const Node<T>& node){
  const Node<T>* n = &node;
  while(n){
    cout << n->data << " ";
    n = n->next;
  }
  cout << endl;
}

template<typename T>
Node<T>* partition(Node<T>* head, int x){
  Node<T>* lBegin = nullptr;
  Node<T>* lEnd = nullptr;
  Node<T>* gBegin = nullptr;
  Node<T>* gEnd = nullptr;

  Node<T>* n = head;
  while(n){
    Node<T>* next = n->next;

    if(n->data < x){
      if(!lBegin){
        lBegin = n;
        lEnd = n;
      }
      else{
        lEnd -> next = n;
        lEnd = n;
      }
      n->next = nullptr;
    }
    if(n->data == x){
      if(!gBegin){
        gBegin = n;
        gEnd = n;
      }
      else{
        n->next = gBegin;
        gBegin = n;
      }
    }
    if(n->data > x){
      if(!gBegin){
        gBegin = n;
        gEnd = n;
      }
      else{
        gEnd -> next = n;
          gEnd = n;
      }
      n->next = nullptr;
    }
    n = next;
  }

  if(lBegin){lEnd->next = gBegin;}
  else{lBegin = gBegin;}

  return lBegin;
}
