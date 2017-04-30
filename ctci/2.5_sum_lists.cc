#include<iostream>
using namespace std;

struct Node{
  int data;
  Node* next;
};

void print(const Node& node);
Node* sumList(const Node& l1, const Node& l2);

int main(){

  Node* l1;
  Node* last;
  for(int i = 0; i < 5; i++){
    Node* n = new Node;
    n->data = i;
    n->next = nullptr;
    if(i == 0){
      l1 = n;
    }
    else{
      last-> next = n;
    }
    last = n;
  }

  Node* l2 = nullptr;
  for(int i = 0; i < 5; i++){
    Node* n = new Node;
    n->data = 6;
    n->next = nullptr;
    if(i == 0){
      l2 = n;
    }
    else{
      last-> next = n;
    }
    last = n;
  }


  print(*l1);
  print(*l2);
  Node* l3 = sumList(*l1, *l2);
  print(*l3);

  return 0;
}

void print(const Node& node){
  const Node* n = &node;
  while(n){
    cout << n->data << " ";
    n = n->next;
  }
  cout << endl;
}

Node* sumList(const Node& l1, const Node& l2){
  const Node* t1 = &l1;
  const Node* t2 = &l2;
  Node* l3 = nullptr;
  Node* last = nullptr;
  int oneUp = 0;

  while(t1 || t2){
    int sum = oneUp;
    if(t1){sum += t1->data;}
    if(t2){sum += t2->data;}

    if(!l3){
      l3 = new Node;
      last = l3;
    }
    else{
      Node* next = new Node;
      last-> next = next;
      last = next;
    }

    last->data = sum%10;
    oneUp = sum/10;

    if(t1){t1 = t1->next;}
    if(t2){t2 = t2->next;}
  }

  if(oneUp > 0){
    Node* next = new Node;
    next->data = oneUp;
    last-> next = next;
  }

  return l3;
}
