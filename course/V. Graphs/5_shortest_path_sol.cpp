#include <vector>
#include <tuple>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;


unordered_map<string,vector<string>> makeGraph(vector<tuple<string,string>> edges){
  unordered_map<string,vector<string>> graph;
  for(auto [A,B] : edges){
    graph[A].push_back(B);
    graph[B].push_back(A);
  }
  return graph;
}

int shortestPath(std::vector<std::tuple<std::string, std::string>> edges, std::string nodeA, std::string nodeB) {
  unordered_map<string,vector<string>> graph = makeGraph(edges);
  unordered_set<string> visited;
//implement BFS
  queue<tuple<string,int>> queue;
  queue.push(tuple<string,int> {nodeA,0});
  visited.insert(nodeA);
  while(queue.size()){
    auto [current, distace] = queue.front();
    queue.pop();
    
    if(current==nodeB){
      return distace;
    }
    for(auto neighbour : graph[current]){
      if(visited.count(neighbour)==0){//if node is not visited
        visited.insert(neighbour);//add to visited
        queue.push(tuple<string,int> {neighbour,distace+1});//push to queue
      }
    }   
  }
  return -1;
}



void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}