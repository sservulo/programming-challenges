#include<iostream>
#include<cstdlib>
#include<unordered_set>
using namespace std;

template<typename T>
struct Node{
  T data;
  Node* next;
};


/*Remove duplicates from a linked list using a hashtable and receiving a pointer to pointer to head*/
template<typename T>
Node<T>* removeDuplicate(Node<T>* head){

  if(!head){return nullptr;}

  unordered_set<T> hash;

  Node<T>** pp = &head;
  Node<T>* entry = head;

  while(entry){
    if(hash.find(entry->data) == hash.end()){
      hash.insert(entry->data);
      pp = &entry->next;
    }
    else{
      *pp = entry->next;
      delete entry;
    }

    entry = (*pp)->next;
  }

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
