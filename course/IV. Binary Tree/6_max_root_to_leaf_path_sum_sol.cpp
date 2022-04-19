#include <limits.h>
#include <algorithm>

using namespace std;

class Node {
  public:
    int val;
    Node* left;
    Node* right;


    Node(int initialVal) {
      val = initialVal;
      left = nullptr;
      right = nullptr;
    }
};



int maxPathSum(Node* root) {
  if(!root){
    return INT_MIN;
  }
  if(!root->left && !root->right){
    return root->val;
  }
  int leftsum = maxPathSum(root->left);
  int rightsum = maxPathSum(root->right);
  return root->val + max(leftsum,rightsum) ;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}