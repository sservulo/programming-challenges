#include<iostream>
#include<stack>
using namespace std;

struct Node{
  int data;
  Node* next;
};

void print(const Node& node);
const Node* findIntersection(const Node& l1, const Node& l2);


int main(){

  Node* intersection;

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

    if(i == 2){
      intersection = n;
    }

    last = n;
  }

  Node* l2 = nullptr;
  for(int i = 0; i < 7; i++){
    Node* n = new Node;
    n->data = 6;
    n->next = nullptr;
    if(i == 0){
      l2 = n;
    }
    else{
      last-> next = n;
    }

    if(i == 5){
      last->next = intersection;
      break;
    }
    last = n;
  }

  print(*l1);
  print(*l2);
  const Node* intersection2 = findIntersection(*l1, *l2);

  cout << intersection2->data << endl;

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

int count(const Node& node){
  int counter = 0;
  const Node* n = &node;
  while(n){
    n = n->next;
    counter++;
  }
  return counter;
}

const Node* advance(const Node& l, int k){
  const Node* n = &l;
  while(k-- > 0){n = n->next;}
  return n;
}

const Node* findIntersection(const Node& l1, const Node& l2){
  int counterL1 = count(l1);
  int counterL2 = count(l2);
  if(counterL1 == 0 || counterL2 == 0){return nullptr;}

  int diffL1 = counterL1 - counterL2;
  const Node* t1 = &l1;
  while(diffL1-- > 0){t1 = t1->next;}

  int diffL2 = counterL2 - counterL1;
  const Node* t2 = &l2;
  while(diffL2-- > 0){t2 = t2->next;}

  while(t1 && t2){
    if(t1 == t2){return t1;}
    t1 = t1->next;
    t2 = t2->next;
  }
  return nullptr;
}
