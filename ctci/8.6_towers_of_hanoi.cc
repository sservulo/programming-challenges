#include<iostream>
#include<stack>
using namespace std;

void hanoi(stack<int>& from, stack<int>& to, stack<int>& aux, int n){
  if(n==0){return;}
  hanoi(from,aux,to,n-1);
  int e = from.top();
  from.pop();
  to.push(e);
  hanoi(aux,to,from,n-1);
}

int main(){
  stack<int> from, to, aux;
  for(int i = 7; i >= 0; i--){
    from.push(i);
    cout << i << " ";
  }
  cout << endl;
  hanoi(from, to, aux, from.size());
  for(int i = 0; i <= 7; i++){
    cout << to.top() << " ";
    to.pop();
  }
  cout << endl;
  return 0;
}
