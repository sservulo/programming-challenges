#include<iostream>
#include<stack>
using namespace std;

void sort(stack<int>* s){
  stack<int> aux;
  while(!s->empty()){
    int data = s->top();
    s->pop();
    if(aux.empty() || aux.top() <= data){
      aux.push(data);
    }
    else{
      int count = 0;
      while(!aux.empty() && aux.top() > data){
        int tData = aux.top();
        s->push(tData);
        aux.pop();
        count++;
      }
      aux.push(data);
      while(count--){
        int tData = s->top();
        aux.push(tData);
        s->pop();
      }
    }
  }
  cout << endl;
  while(!aux.empty()){
    int tData = aux.top();
    s->push(tData);
    aux.pop();
  }
}

int main(){
  stack<int> s;
  cout << "input: ";
  for(int i = 60; i > 0; i--){
    int data = rand()%100;
    cout << data << " ";
    s.push(data);
  }
  cout << endl;
  sort(&s);
  while(!s.empty()){
    int data = s.top();
    cout << data << " ";
    s.pop();
  }
  cout << endl;

  return 0;
}
