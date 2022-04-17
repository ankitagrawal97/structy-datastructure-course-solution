#include <vector>
#include <string>
#include <algorithm>
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
//inOrder
//left node right

//postorder
//left right node

Node* buildTreeInPost(std::vector<std::string> inorder, std::vector<std::string> postorder) {
  if(inorder.size()==0){
    return nullptr;
  }
  string val = postorder[postorder.size()-1];
  Node* root = new Node(val);
  auto ptr = find(inorder.begin(),inorder.end(),val);
  //make slices excluding the root node
  vector<string> inLeft(inorder.begin(),ptr);
  vector<string> inRight(ptr+1,inorder.end());
  vector<string> postLeft(postorder.begin(),postorder.begin() + inLeft.size());
  vector<string> postRight(postorder.begin() + inLeft.size(), postorder.end()-1);
  
  root->left = buildTreeInPost(inLeft,postLeft);
  
  root->right = buildTreeInPost(inRight,postRight);
  
  return root;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}