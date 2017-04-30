#include<iostream>
using namespace std;

struct Node{
  int data;
  int min;
  Node* next;
};

class Stack{
  Node* head = nullptr;
  public:
    bool isEmpty();
    int top();
    int min();
    int pop();
    void push(int data);
};

bool Stack::isEmpty(){
  return head == nullptr;
}

int Stack::top(){
  if(isEmpty()){throw 0;}
  return head->data;
}

int Stack::min(){
  if(isEmpty()){throw 0;}
  return head->min;
}

int Stack::pop(){
  if(isEmpty()){throw 0;}
  int data = head->min;
  Node* toDelete = head;
  head = head->next;
  delete toDelete;
  return data;
}

void Stack::push(int data){
  Node* newNode = new Node;
  newNode->data = data;
  if(isEmpty()){
    newNode->min = data;
  }
  else{
    newNode->min = data <= head->min? data : head->min;
  }
  newNode->next = head;
  head = newNode;
}

int main(){
  Stack s;
  cout << "empty: " << s.isEmpty() << endl;
  for(int i = 20; i > 0; i--){
    s.push(i);
  }
  cout << "min: " << s.min() << endl;
  s.pop();
  cout << "min: " << s.min() << endl;
  cout << "empty: " << s.isEmpty() << endl;
  cout << "min: " << s.min() << endl;
  for(int i = 0; i < 19; i++){
    s.pop();
  }
  cout << "empty: " << s.isEmpty() << endl;
  return 0;
}
