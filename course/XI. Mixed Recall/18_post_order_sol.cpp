#include <vector>
#include <string>
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

void postOrder(Node* root, vector<string> &vals){
  if(!root){
    return;
  }
  //left
  postOrder(root->left,vals);
  //right
  postOrder(root->right,vals);
  vals.push_back(root->val);
  /
}

std::vector<std::string> postOrder(Node* root) {
  vector<string> vals;
  postOrder(root,vals);
  return vals;
}



void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}