#include<iostream>
using namespace std;

struct Node{
  int data;
  Node* next;
};

void print(Node& node);
Node* sumList(Node* l1, Node* l2);
Node* sumListInternal(Node* l1, Node* l2, int* oneUp);

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
  for(int i = 0; i < 3; i++){
    Node* n = new Node;
    n->data = 9;
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
  Node* l3 = sumList(l1, l2);
  print(*l3);

  return 0;
}

void print(Node& node){
  Node* n = &node;
  while(n){
    cout << n->data << " ";
    n = n->next;
  }
  cout << endl;
}

int count(Node* node){
  int counter = 0;
  Node* n = node;
  while(n){
    n = n->next;
    counter++;
  }
  return counter;
}

Node* pad(Node* node, int count){
  Node* newHead = node;
  while(count--){
    Node* pad = new Node;
    pad->data = 0;
    pad->next = newHead;
    newHead = pad;
  }
  return newHead;
}

Node* sumList(Node* l1, Node* l2){

  int countL1 = count(l1);
  int countL2 = count(l2);
  if(countL1 != countL2 && countL1 < countL2){l1 = pad(l1, countL2 - countL1);}
  if(countL1 != countL2 && countL2 < countL1){l2 = pad(l2, countL1 - countL2);}

  print(*l1);
  print(*l2);

  int oneUp = 0;
  Node* sum = sumListInternal(l1, l2, &oneUp);

  if(oneUp > 0){
    Node* oneUpNode = new Node;
    oneUpNode->data = oneUp;
    oneUpNode->next = sum;
    sum = oneUpNode;
  }

  return sum;
}

Node* sumListInternal(Node* l1, Node* l2, int* oneUp){

  if(!l1 && !l2){return nullptr;}

  int lesserOneUp = 0;
  Node* lesserSum = sumListInternal(l1->next, l2->next, &lesserOneUp);

  int sum = l1->data + l2->data + lesserOneUp;

  Node* sumNode = new Node;
  sumNode->data = sum%10;
  sumNode->next = lesserSum;

  *oneUp = sum/10;

  return sumNode;
}
