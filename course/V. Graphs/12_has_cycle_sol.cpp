#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool detectCycle(std::unordered_map<char, std::vector<char>> graph,unordered_set<char> &visiting,unordered_set<char> &visited, char currentNode){
  if(visiting.count(currentNode)){
    return true;
  }
  if(visited.count(currentNode)){
    return false;
  }
  visiting.insert(currentNode);
  for(auto neighbor : graph[currentNode]){
    if(detectCycle(graph,visiting,visited,neighbor)){
      return true;
    }
  }
  visiting.erase(currentNode);
  visited.insert(currentNode);
  return false;
}

bool hasCycle(std::unordered_map<char, std::vector<char>> graph) {
  unordered_set<char> visiting;
    unordered_set<char> visited;
  for(auto [node,neighbor] : graph){
    if(detectCycle(graph,visiting,visited,node)){
      return true;
    }
  }
  return false;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}