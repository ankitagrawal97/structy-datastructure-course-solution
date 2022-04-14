#include <vector>
#include <tuple>
#include <string>
#include <unordered_map>

std::unordered_map<std::string, std::vector<std::string>> buildGraph(std::vector<std::tuple<std::string, std::string>> edges) {
  std::unordered_map<std::string, std::vector<std::string>> graph;
  for (auto [a, b] : edges) {
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  return graph;
}

bool isBipartite(std::unordered_map<std::string, std::vector<std::string>> graph, std::unordered_map<std::string, bool> &coloring, std::string node, bool currentColor) {
  if (coloring.count(node) > 0) {
    return currentColor == coloring[node];
  }
  
  coloring[node] = currentColor;
  for (std::string neighbor : graph[node]) {
    if (!isBipartite(graph, coloring, neighbor, !currentColor)) {
      return false;
    }
  }
  
  return true;
}

bool tolerantTeams(std::vector<std::tuple<std::string, std::string>> rivalries) {
  std::unordered_map<std::string, std::vector<std::string>> graph = buildGraph(rivalries);
  std::unordered_map<std::string, bool> coloring;
  for (auto [ node, neighbors ] : graph) {
    if (coloring.count(node) == 0 && !isBipartite(graph, coloring, node, false)) {
      return false;
    } 
  }
  return true;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}