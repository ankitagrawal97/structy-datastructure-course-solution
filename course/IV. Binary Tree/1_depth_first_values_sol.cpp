#include <string>
#include <vector>
#include <stack>
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


//iterative sol S:0(n) T:O(n)
/*std::vector<std::string> depthFirstValues(Node* root) {
  vector<string> values;
  stack<Node*> stac;
  if(root){
    stac.push(root);
  }
  while(stac.size()){
    Node* currNode = stac.top();
    stac.pop();
    values.push_back(currNode->val);
    if(currNode->right){
      stac.push(currNode->right);
    }
    if(currNode->left){
      stac.push(currNode->left);
    }
  }
  return values;
}*/
//==========================================================
//recursive sol S:O(n) T:O(n)
void dfs(Node* root, vector<string> &values){
  if(!root){
    return;
  }
  values.push_back(root->val);
  dfs(root->left,values);
  dfs(root->right,values);
}

std::vector<std::string> depthFirstValues(Node* root) {

  vector<string> values;
  dfs(root,values);
  return values;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}