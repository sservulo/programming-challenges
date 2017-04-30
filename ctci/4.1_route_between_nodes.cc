#include<iostream>
#include<vector>
#include<fstream>
//#include<cstring>
#include<regex>
using namespace std;

struct Node{
  int value;
  bool visited;
  vector<Node*> children;
};

bool DFS(Node* a, Node* b){
  a->visited = true;
  for(auto& c : a->children){
    if(c == b){return true;}
    if(!c->visited && DFS(c,b)){return true;}
  }
  return false;
}

bool hasPathDFS(vector<Node*>* graph, Node* a, Node* b){
  if(!a || !b){return false;}
  if(DFS(a, b)){return true;}
  for(auto& node : *graph){
    node->visited = false;
  }
  return DFS(b, a);
}

vector<Node*>* fileToGraph(string filename){
  std::ifstream infile(filename);
  string line;
  getline(infile, line);
  int n = stoi(line);
  vector<Node*>* graph = new vector<Node*>();
  for(int i = 0; i < n; i++){
    Node* newNode = new Node;
    newNode->value = i;
    graph->push_back(newNode);
  }

  int sourceIndex = 0;
  while(getline(infile,line)){
    regex re("\\s");
    sregex_token_iterator it(line.begin(), line.end(), re, -1);
    sregex_token_iterator reg_end;
    for (; it != reg_end; ++it) {
      int destIndex = stoi(it->str());
      graph->at(sourceIndex)->children.push_back(graph->at(destIndex));
    }
    sourceIndex++;
  }

  for(const auto& node : *graph){
    cout << node->value << ": ";
    for(const auto& child : node->children){
      cout << child->value << " ";
    }
    cout << endl;
  }

  return graph;
}


int main(){
  vector<Node*>* graph = fileToGraph("/home/samuel/Onedrive/Google/valendo/input-4.1.txt");
  cout << hasPathDFS(graph, graph->at(0), graph->at(4));
  return 0;
}
