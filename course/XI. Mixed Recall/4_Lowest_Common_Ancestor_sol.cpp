#include <string>
#include <vector>
#include <unordered_set>

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


vector<string> findPath(Node* root,string target){
  if(!root){
    return vector<string> {};
  }
  if(root->val == target){
    return vector<string> {root->val};
  }
  vector<string> leftpath = findPath(root->left,target);
  if(leftpath.size()){
    leftpath.push_back(root->val);
    return leftpath;
  }
  vector<string>  rightpath = findPath(root->right,target);
  if(rightpath.size()){
    rightpath.push_back(root->val);
    return rightpath;
  }
  
  return vector<string>{};
}
std::string lowestCommonAncestor(Node* root, std::string val1, std::string val2) {
vector<string> path1 = findPath(root,val1);
  vector<string> path2 = findPath(root,val2);
  
  unordered_set<string> set1(path1.begin(),path1.end());
  for(auto str : path2){
    if(set1.count(str)>0){
      return str;
    }
  }
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}