#include <vector>
#include <queue>

class Node {
  public:
    float val;
    Node* left;
    Node* right;


    Node(float initialVal) {
      val = initialVal;
      left = nullptr;
      right = nullptr;
    }
};

void levelOrder(Node* root, std::vector<std::vector<float>> &levels, int level){
  if(!root){
    return;
  }
  if(levels.size()==level){
    levels.push_back(std::vector<float>{root->val});
  }else{
    levels[level].push_back(root->val);
  }
  levelOrder(root->left,levels,level+1);
  levelOrder(root->right,levels,level+1);
}
float avg (std::vector<float> nums){
  float sum = 0;
  for(auto s : nums){
    sum += s;
  }
  return sum/nums.size();
}

std::vector<float> levelAverages(Node* root) {
  std::vector<std::vector<float>> levels;
  levelOrder(root,levels,0);
  std::vector<float> result;
  for(auto vec : levels){
    result.push_back(avg(vec));
  }
  return result;
}





void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}