#include <vector>
#include <tuple>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_map<string,vector<string>> makeGraph(vector<tuple<string,string>> edges){
  unordered_map<string,vector<string>> graph;
  for(auto [node,neighbour] : edges){
    graph[node].push_back(neighbour);
    graph[neighbour].push_back(node);
  }
  return graph;
}

bool hasPath(unordered_map<string,vector<string>> graph,unordered_set<string> &visited, string src, string dst){
  if(src == dst){
    return true;
  }
  if(visited.count(src)){
    return false;
  }
  visited.insert(src);
  for(auto neighbour : graph[src]){
    if(hasPath(graph,visited,neighbour,dst)){
      return true;
    }
  }
  return false;
}

bool undirectedPath(vector<tuple<string,string>> edges, string src, string dst) {
  unordered_map<string,vector<string>> graph = makeGraph(edges);
  unordered_set<string> visited;
  return hasPath(graph,visited,src,dst);
}



void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}