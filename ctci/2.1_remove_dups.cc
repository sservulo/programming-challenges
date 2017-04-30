#include<iostream>
#include<cstdlib>
#include<unordered_set>
using namespace std;

template<typename T>
struct Node{
  T data;
  Node* next;
};


/*Remove duplicates from a linked list using a hashtable and receiving a pointer to head*/
template<typename T>
Node<T>* removeDuplicate(Node<T>* head){

  if(!head){return nullptr;}

  unordered_set<T> hash;

  Node<T>* previous = head;
  Node<T>* next = head->next;

  hash.insert(head->data);

  while(next){
    if(hash.find(next->data) == hash.end()){
      hash.insert(next->data);
      previous = next;
    }
    else{
      previous->next = next->next;
      delete next;
    }
    next = previous->next;
  }

  //previous->next = nullptr;

  return head;
}

template<typename T>
void print(const Node<T>& head){
  const Node<T>* n = &head;
  while(n){
    cout << n->data << " ";
    n = n->next;
  }
  cout << endl;
}

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
  removeDuplicate(head);
  print(*head);
  return 0;
}
