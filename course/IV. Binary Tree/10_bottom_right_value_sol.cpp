#include <string>
#include <queue>

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



std::string bottomRightValue(Node* root) {
  std::queue<Node*> q;
  if(root){
    q.push(root);
  }
  Node* curr = nullptr;
  while(q.size()>0){
    curr = q.front();
    q.pop();
    if(curr->left){
      q.push(curr->left);
    }
    if(curr->right){
      q.push(curr->right);
    }
    
    
  }
  return curr->val;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}