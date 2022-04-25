#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
vector<string> topologicalOrder(unordered_map<string, vector<string>> graph) {
  //visiting parent before its childeren is topological order.
  //this order cannot be determined if there is a cycle in the graph

  //making a map to store the count of parents of each node
  unordered_map<string,int> numParents;
  for(auto [node,children] : graph){
    if(numParents.count(node) == 0){
      numParents[node] = 0;
    }
    for(string child : children){
      numParents[child]++;
    }
  }
  //ready vetor
  //nodes to pushed with 0 parents
  vector<string> ready;
  for(auto [node,num]: numParents){
    if(num==0){
      ready.push_back(node);
    }
  }
  vector<string> order;
  //remove the last element from ready vector , add it to order vector
  //decrease the count of parent of the removed element from the parent map
  //if count of an  node becomes 0  then push it to ready vector
  while(ready.size()>0){
    string currentNode = ready.back();
    ready.pop_back();
    order.push_back(currentNode);
    for(auto children : graph[currentNode]){
      numParents[children]--;
      if(numParents[children] == 0) {
        ready.push_back(children);
      }
    }
  }
  
  return order;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}