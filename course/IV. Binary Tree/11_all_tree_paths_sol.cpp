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



vector<vector<string>> allTreePaths(Node* root) {
  if(!root){
    return vector<vector<string>>();
  }
  if(!root->left && !root->right){
    return vector<vector<string>> { vector<string>{root->val}};
  }
  vector<vector<string>> result;
  for(auto subPath : allTreePaths(root->left)){
    subPath.insert(subPath.begin(),root->val);
    result.push_back(subPath);
  }
  for(auto subPath : allTreePaths(root->right)){
    subPath.insert(subPath.begin(),root->val);
    result.push_back(subPath);
  }
  return result;
}



void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}