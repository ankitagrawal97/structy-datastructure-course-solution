#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;
//helper function to make a graph from the given edge list.
unordered_map<int,vector<int>> makeGraph(int n, vector<vector<int>> roads){
  unordered_map<int,vector<int>> graph;
  for(int i = 0 ;i<n;i++){
    graph[i] = vector<int> ();
  }
  for(vector<int> edge : roads){
    int a = edge[0];
    int b = edge[1];
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  return graph;
}
bool valid(unordered_map<int,vector<int>> graph, unordered_set<int> &visited, int node, int previousNode){
  if(visited.count(node)){
    return false;
  }
  visited.insert(node);
  for(auto neighbour : graph[node]){
    if(neighbour!=previousNode && !valid(graph,visited,neighbour,node)){
      return false;
    }
  }
  return true;
}
bool rareRouting(int n, std::vector<std::vector<int>> roads) {
  unordered_map<int,vector<int>> graph = makeGraph(n ,roads);
  unordered_set<int> visited;
  
  bool isValid = valid(graph,visited,0,-1); //to check if a unique path exists
  bool hasVisited = visited.size() == n;    //to check if all cities are visited i.e no disconnected components
  
  return isValid && hasVisited;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}