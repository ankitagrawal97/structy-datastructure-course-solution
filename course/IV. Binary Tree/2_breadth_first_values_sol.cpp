#include <string>
#include <vector>
#include <queue>

using namespace std;

class Node {
  public:
    std::string val;
    Node* left;
    Node* right;


    Node(std::string initialVal) {
      val = initialVal;
      left = nullptr;
      right = nullptr;
    }
};


//iterative sol S:O(n) T:O(n)
std::vector<std::string> breadthFirstValues(Node* root) {
  queue<Node*> q;
  vector<string> values;
  if(root){
    q.push(root);
  }
  while(q.size()){
    Node* curr = q.front();
    values.push_back(curr->val);
    q.pop();
    if(curr->left){
      q.push(curr->left);
    }
    if(curr->right){
      q.push(curr->right);
    }
  }
  return values;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}