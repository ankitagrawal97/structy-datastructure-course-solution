#include <vector>
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
void inOrderTraverse(Node* root, vector<int> &vals){
  if(!root){
    return;
  }
  inOrderTraverse(root->left,vals);
  vals.push_back(root->val);
  inOrderTraverse(root->right,vals);
}


bool isBinarySearchTree(Node* root) {
  vector<int> vals;
  inOrderTraverse(root,vals);
  for(int i = 0 ; i < vals.size() -1; i++){
    if(vals[i] > vals[i+1]){
      return false;
    }
  }
  
  return true;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}