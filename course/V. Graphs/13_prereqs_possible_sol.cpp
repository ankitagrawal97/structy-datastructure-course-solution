#include <vector>
#include <tuple>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_map<int,vector<int>> makegraph(vector<tuple<int,int>> prereqs){
  unordered_map<int,vector<int>> graph;
  for(auto [node,neighbor] : prereqs){
    graph[node].push_back(neighbor);
  }
  return graph;
}

bool hasCycle(unordered_map<int,vector<int>> graph,unordered_set<int> &visiting,unordered_set<int> &visited, int currentNode){
  if(visiting.count(currentNode)){
    return true;
  }
  if(visited.count(currentNode)){
    return false;
  }
  visiting.insert(currentNode);
  for(auto neighbor : graph[currentNode]){
    if(hasCycle(graph,visiting,visited,neighbor)){
      return true;
    }
  }
  visiting.erase(currentNode);
  visited.insert(currentNode);
  return false;
}

bool prereqsPossible(int numCourses, std::vector<std::tuple<int, int>> prereqs) {
  unordered_map<int,vector<int>> graph = makegraph(prereqs);
  unordered_set<int> visited;
  unordered_set<int> visiting;
  for(int node = 0 ; node < numCourses ; node++){
    if(hasCycle(graph,visiting,visited,node)){
      return false;
    }
  }
  return true;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}