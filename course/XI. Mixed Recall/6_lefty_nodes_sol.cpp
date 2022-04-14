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

void leftyNodes(Node* root, int level, vector<string> &result){
  if(!root){
    return;
  }
  if(result.size()==level){
    result.push_back(root->val);
  }
  leftyNodes(root->left,level+1,result);
  leftyNodes(root->right,level+1,result);
  
}
std::vector<std::string> leftyNodes(Node* root) {
  vector<string> result;
    leftyNodes(root,0,result);
  return result;
}



void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}