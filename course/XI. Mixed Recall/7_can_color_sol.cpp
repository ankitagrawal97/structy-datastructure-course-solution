#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

bool valid(std::unordered_map<std::string, std::vector<std::string>> graph, std::unordered_map<std::string, bool> &coloring, std::string node, bool currentColor) {
  //check if the node is already visited 
  if (coloring.count(node) > 0) {
      //if visited , check if its the correct color
    return currentColor == coloring[node];
  }
  //if not, assign it the color
  coloring[node] = currentColor;
  //iterate through all the neighbours of the node and color it opposite
  for (std::string neighbor : graph[node]) {
    if (!valid(graph, coloring, neighbor, !currentColor)) {
      return false;
    }
  }
  
  return true;
}

bool canColor(std::unordered_map<std::string, std::vector<std::string>> graph) {
  std::unordered_map<std::string, bool> coloring;
  //iteration via all nodes is required to avoid the case of disjointed graph
  for (auto [ node, neighbors ] : graph) {
    if (coloring.count(node) == 0 && !valid(graph, coloring, node, true)) {
      return false;
    }
  }
  return true;
}
  

void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}