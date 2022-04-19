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



int treeMinValue(Node* root) {
  if(!root){
    return INT_MAX;
  }
  return min({root->val,treeMinValue(root->left),treeMinValue(root->right)});
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}