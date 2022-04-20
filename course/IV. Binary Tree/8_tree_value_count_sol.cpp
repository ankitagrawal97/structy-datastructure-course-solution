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

void dfs(Node* root, int targetVal, int &count){
  if(!root){
    return;
  }
  if(root->val == targetVal){
    count++;
  }
  dfs(root->left,targetVal,count);
  dfs(root->right,targetVal,count);
}

int treeValueCount(Node* root, int targetVal) {
  int count = 0;
  dfs(root,targetVal,count);
  return count;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}