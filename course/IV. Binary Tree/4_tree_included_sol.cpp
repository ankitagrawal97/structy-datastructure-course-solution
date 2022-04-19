#include <string>

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



bool treeIncludes(Node* root, std::string targetVal) {
  if(!root){
    return false;
  }
  if(root->val==targetVal){
    return true;
  }
  
  return treeIncludes(root->left,targetVal)||treeIncludes(root->right,targetVal);
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}