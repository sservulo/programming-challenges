#include<iostream>
#include<stack>
using namespace std;

struct Node{
  int data;
  Node* next;
};

void print(const Node& node);
const Node* findLoopNode(const Node& head);


int main(){

  Node* loopNode;

  Node* l1;
  Node* last;
  int numNodes = 25;
  for(int i = 0; i < numNodes; i++){
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

    // if(i == 13){
    //   loopNode = n;
    // }
    // if(i == numNodes - 1){
    //   n->next = loopNode;
    // }
  }

  const Node* foundLoopNode = findLoopNode(*l1);

  if(foundLoopNode){
    cout << foundLoopNode->data << endl;
  }
  else{cout << "oops, lista sem loops" << endl;}


  return 0;
}

const Node* findLoopNode(const Node& head){
  const Node* slow = &head;
  const Node* runner = &head;
  if(!slow){return nullptr;}

  while(runner->next && runner->next->next){
    runner = runner->next->next;
    slow = slow->next;
    if(slow == runner){break;}
  }
  if(slow != runner){return nullptr;}

  slow = &head;
  while(slow != runner){
    runner = runner->next;
    slow = slow->next;
  }

  return slow;
}
