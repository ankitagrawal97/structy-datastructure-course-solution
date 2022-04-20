#include <vector>
#include <string>
#include <queue>
#include <tuple>
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
//Both Solution has same complexity

//iterative solution using queue
std::vector<std::vector<std::string>> treeLevels(Node* root) {
  queue<tuple<Node*,int>> queue;
  vector<vector<string>> result;
  if(root){
  queue.push(tuple{root,0});  
  }
  while(queue.size()){
    auto [curr,level] = queue.front();
    queue.pop();
      if(result.size()==level){
        result.push_back(vector<string>{curr->val});
      }else{
        result[level].push_back(curr->val);
      }
      
      if(curr->left){
        queue.push(tuple{curr->left,level+1});
      }
      if(curr->right){
        queue.push(tuple{curr->right,level+1});
      }
  }
  return result;
}

/* 
//recursive solution
void _treeLevels(Node* root, vector<vector<string>> &levels, int level){
  if(!root){
    return;
  }
  if(levels.size()==level){
    levels.push_back(vector<string>{root->val});
  }else{
    levels[level].push_back(root->val);
  }
  _treeLevels(root->left,levels,level+1);
  _treeLevels(root->right,levels,level+1);
  
}

std::vector<std::vector<std::string>> treeLevels(Node* root) {
  vector<vector<string>> levels;
  _treeLevels(root,levels,0);
  return levels;
}

*/

void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}