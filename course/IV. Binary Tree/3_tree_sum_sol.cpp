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



int treeSum(Node* root) {
  if(!root){
    return 0;
  }
  return root->val + treeSum(root->left) + treeSum(root->right);
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}