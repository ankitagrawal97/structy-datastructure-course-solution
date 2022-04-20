#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int explore(unordered_map<int,vector<int>> graph, unordered_set<int> &visited, int currentNode){
  if(visited.count(currentNode)){
    return 0;
  }
  visited.insert(currentNode);
  
  int size = 1;
  for(auto neighbour : graph[currentNode]){
    size += explore(graph,visited,neighbour);
  }
  
  return size;
  
}

int largestComponent(std::unordered_map<int, std::vector<int>> graph) {
  unordered_set<int> visited;
  int maxsize = 0;
  for(auto [node,neighbour] : graph){
    int size = explore(graph,visited,node);
    if(size>maxsize){
      maxsize = size;
    }
  }
  return maxsize;
}



void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}