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
//inorder : left root right
//preorder : root left right

//recursive sol 
// O(n*n) time complexity.
//O(n*n) space complexity
Node* buildTreeInPre(std::vector<std::string> inorder, std::vector<std::string> preorder) {
  if(inorder.size() == 0){
    return nullptr;
  }
  string val = preorder[0];
  Node* root = new Node(val);
  auto ptr = find(inorder.begin(),inorder.end(),val);
  vector<string> inLeft(inorder.begin(),ptr);
  vector<string> inRight(ptr + 1 , inorder.end());
  vector<string> preLeft(preorder.begin()+1,preorder.begin()+1+inLeft.size());
  vector<string> preRight(preorder.begin()+1+inLeft.size(),preorder.end());
  
  root->left = buildTreeInPre(inLeft,preLeft);
  root->right = buildTreeInPre(inRight,preRight);
  return root;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}