#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

bool hasPath(unordered_map<string, vector<string>> graph, string src, string dst) {
  if(src==dst){
    return true;
  }
  for(auto neighbour : graph[src]){
    if(hasPath(graph,neighbour,dst)){
      return true;
    }
  }
  return false;
}



void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}