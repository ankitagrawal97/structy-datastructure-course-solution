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



bool binarySearchTreeIncludes(Node* root, int targetVal) {
  if(!root){
    return false;
  }
  if(root->val == targetVal){
    return true;
  }
  if(root->val>targetVal){
    return binarySearchTreeIncludes(root->left,targetVal);
  }else{
    return binarySearchTreeIncludes(root->right,targetVal);
  }
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}