#include<iostream>
#include<cstdlib>
#include<unordered_set>
using namespace std;

template<typename T>
struct Node{
  T data;
  Node<T>* next;
};


/*Remove duplicates from a linked list using bruteforce receiving a pointer to head*/
template<typename T>
Node<T>* removeDuplicate(Node<T>* head){

  Node<T>* node = head;
  //while(node){
    Node<T>* next = node->next;
    while(next){
      if(next->data == node->data){
        Node<T>** pp = &next;
        *pp = next->next;
        //delete next;
        //next = n;
      }
      else{next = next->next;}
    }
  //   node = node->next;
  // }
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
