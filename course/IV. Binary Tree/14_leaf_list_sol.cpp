#include <vector>
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
void _leafList(Node* root,std::vector<std::string> &result){
  if(!root){
    return;
  }
  if(!root->left && !root->right){
    result.push_back(root->val);
  }
  _leafList(root->left,result);
  _leafList(root->right,result);
  
}


std::vector<std::string> leafList(Node* root) {
  std::vector<std::string> result;
  _leafList(root,result);
  return result;
}



void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}