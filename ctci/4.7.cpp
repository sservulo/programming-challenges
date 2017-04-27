#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

struct Node{
  int value;
  bool built;
  unordered_set<Node*> deps;
};

vector<Node*> getBuildOrder(vector<Node*>& graph){
  vector<Node*> build;
  if(graph.empty()){return build;}

  Node* builtNode = nullptr;
  int attempts = graph.size();
  while(attempts--){
    for(auto& n : graph){
      if(!n->built && n->deps.empty()){
        n->built = true;
        builtNode = n;
        build.push_back(n);
        break;
      }
    }
    if(!builtNode){throw 0;}
    for(auto& n : graph){
      n->deps.erase(builtNode);
    }
    builtNode = nullptr;
  }
  return build;
}


vector<Node*> getDependencies(){
  vector<Node*> graph;
  int n = 6;
  for(int i = 0; i < n; i++){
    Node* newNode = new Node;
    newNode->value = i;
    newNode->built = false;
    graph.push_back(newNode);
  }

  // graph[0]->deps.insert(graph[1]);
  // graph[1]->deps.insert(graph[2]);
  // graph[2]->deps.insert(graph[0]);

  graph[3]->deps.insert(graph[0]);
  graph[1]->deps.insert(graph[5]);
  graph[3]->deps.insert(graph[1]);
  graph[0]->deps.insert(graph[5]);
  graph[2]->deps.insert(graph[3]);




  // dependencies[1].insert(2);
  // dependencies[2].insert(0);


  // dependencies[3].insert(0);
  // dependencies[1].insert(5);
  // dependencies[3].insert(1);
  // dependencies[0].insert(5);
  // dependencies[2].insert(3);
  return graph;
}

int main(){
  vector<Node*> graph = getDependencies();
  vector<Node*> build = getBuildOrder(graph);
  for(auto& n : build){
    cout << n->value << " ";
  }
  cout << endl;
  return 0;
}
