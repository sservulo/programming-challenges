#include<iostream>
#include<vector>
using namespace std;

struct Node{
  int data;
  Node* next;
};

class SetOfStacks{
  int maxSize;
  vector<Node*> stacks;
  vector<int> stacksSize;
  public:
    explicit SetOfStacks(int max);
    bool isEmpty();
    int top();
    int pop();
    int popAt(int index);
    void push(int data);
};

SetOfStacks::SetOfStacks(int max){
  maxSize = max;
}

bool SetOfStacks::isEmpty(){
  return stacks.empty();
}

int SetOfStacks::top(){
  if(isEmpty()){throw 0;}
  Node* top = stacks[stacks.size()-1];
  return top->data;
}

int SetOfStacks::popAt(int index){
  if(index >= stacks.size()){throw 0;}
  Node* top = stacks[index];
  Node* next = top->next;
  if(next){
    stacks[index] = next;
    stacksSize[index]--;
  }
  else{
    stacks.erase(stacks.begin()+index);
    stacksSize.erase(stacksSize.begin()+index);
  }
  int data = top->data;
  delete top;

  for(const auto& i: stacksSize){
    cout << i << " ";
  }
  cout << endl;

  return data;
}

int SetOfStacks::pop(){
  if(isEmpty()){throw 0;}
  return popAt(stacks.size()-1);
}

void SetOfStacks::push(int data){
  Node* newNode = new Node;
  newNode->data = data;
  int lastStack = stacksSize.size()-1;
  if(isEmpty() || stacksSize[lastStack]+1 > maxSize){
    stacks.push_back(newNode);
    stacksSize.push_back(1);
  }
  else{
    Node* top = stacks[lastStack];
    newNode->next = top;
    stacks[lastStack] = newNode;
    stacksSize[lastStack]++;
  }
}

int main(){
  SetOfStacks s(3);
  cout << "empty: " << s.isEmpty() << endl;
  for(int i = 0; i < 15; i++){
    s.push(i);
  }
  s.popAt(2);
  cout << "empty: " << s.isEmpty() << endl;
  for(int i = 0; i < 14; i++){
    s.pop();
  }
  cout << "empty: " << s.isEmpty() << endl;
  return 0;
}
