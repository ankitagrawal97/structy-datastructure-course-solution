#include <vector>
#include <tuple>
#include <string>
#include <unordered_map>

using namespace std;

string topologicalOrder(unordered_map<int,vector<int>> graph){
  unordered_map<int, int> numParents;
  for(auto [node,neighbors] : graph){
    if(numParents.count(node)==0){
      numParents[node] = 0;
    }
    for(auto neighbor : neighbors){
      numParents[neighbor]++;
    }
  }
  vector<int> ready;
  for(auto [node,count] : numParents){
    if(count == 0){
      ready.push_back(node);
    }
  }
  string order = "";
  while(ready.size()){
    int currentNode = ready.back();
    ready.pop_back();
    order += to_string(currentNode);
    
    for(auto child : graph[currentNode]){
      numParents[child]--;
      if(numParents[child]==0){
        ready.push_back(child);
      } 
    }
  }
  return order;
}

std::string safeCracking(std::vector<std::tuple<int, int>> hints) {
  unordered_map<int, vector<int>> graph;
  for(auto[a,b] : hints){
    graph[a].push_back(b);
  }
  return topologicalOrder(graph);
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}