#include<iostream>
#include<stack>
using namespace std;

struct Node{
  int data;
  Node* next;
};

void print(const Node& node);
bool isPalindrom(const Node& node);


int main(){

  Node* l1;
  Node* last;
  for(int i = 0; i < 3; i++){
    Node* n = new Node;
    n->data = i%2;
    n->next = nullptr;
    if(i == 0){
      l1 = n;
    }
    else{
      last-> next = n;
    }
    last = n;
  }

  print(*l1);
  cout << isPalindrom(*l1);

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

bool isPalindrom(const Node& node){

  int counter = count(node);
  stack<int> s;
  const Node* n = &node;

  for(int i = 0; i < counter/2; i++){
    s.push(n->data);
    n = n->next;
  }

  if(counter%2 == 1){n = n->next;}

  for(int i = 0; i < counter/2; i++){
    int j = s.top();
    s.pop();
    if(j != n->data){return false;}
    n = n->next;
  }

  return true;
}
