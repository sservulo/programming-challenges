#include<iostream>
#include<stack>
using namespace std;

class MyQueue{
  stack<int> oldest;
  stack<int> newest;
  void dequeue(stack<int>* const from, stack<int>* const to);
  public:
    bool isEmpty();
    int peek();
    int pop();
    void push(int data);
};

void MyQueue::dequeue(stack<int>* const from, stack<int>* const to){
  while(!from->empty()){
    int data = from->top();
    to->push(data);
    from->pop();
  }
}

bool MyQueue::isEmpty(){
  return oldest.empty() && newest.empty();
}

int MyQueue::peek(){
  if(isEmpty()){throw 0;}
  dequeue(&newest, &oldest);
  return oldest.top();
}

int MyQueue::pop(){
  if(isEmpty()){throw 0;}
  dequeue(&newest, &oldest);
  int data = oldest.top();
  oldest.pop();
  return data;
}

void MyQueue::push(int data){
  dequeue(&oldest, &newest);
  newest.push(data);
}

int main(){
  MyQueue q;
  cout << "empty: " << q.isEmpty() << endl;
  for(int i = 0; i < 15; i++){
    q.push(i);
  }
  cout << "peek: " << q.peek() << endl;
  cout << "empty: " << q.isEmpty() << endl;
  q.push(100);
  cout << "peek: " << q.peek() << endl;
  for(int i = 0; i < 15; i++){
    q.pop();
  }
  cout << "peek: " << q.peek() << endl;
  q.pop();
  cout << "empty: " << q.isEmpty() << endl;
  return 0;
}
