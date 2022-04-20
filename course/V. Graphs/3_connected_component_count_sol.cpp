#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

bool explore(unordered_map<int,vector<int>> graph,unordered_set<int> &visited, int currentNode){
  if(visited.count(currentNode)){
    return false;
  }
  visited.insert(currentNode);
  
  for(auto neighbour : graph[currentNode]){
    explore(graph,visited,neighbour);
    }
  return true;//only return true when all the neighbours are visited
}

int connectedComponentsCount(std::unordered_map<int, std::vector<int>> graph) {
  int count = 0;
  unordered_set<int> visited;
  
  for(auto [node,neighbour] : graph){
    if(explore(graph,visited,node)){
      count++;
    }
  }
  return count;
}



void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}