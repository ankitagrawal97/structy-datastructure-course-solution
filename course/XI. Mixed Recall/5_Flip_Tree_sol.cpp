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


Node* flipTree(Node* root) {
  if(!root){
    return nullptr;
  }
  //temp variable
  Node* temp = root->left;
  root->left = root->right;
  root->right = temp;
  //recursive
  flipTree(root->left);
  flipTree(root->right);
  return root;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}