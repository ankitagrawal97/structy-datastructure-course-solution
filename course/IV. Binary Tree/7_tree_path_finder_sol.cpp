#include <vector>
#include <string>
#include <algorithm>

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

std::vector<std::string>* _pathFinder(Node* root, std::string targetVal) {
  if (root == nullptr) {
    return nullptr;
  }
  if (root->val == targetVal) {
    return new std::vector<std::string>({ root->val });
  }
  
  std::vector<std::string>* left = _pathFinder(root->left, targetVal);
  if (left != nullptr) {
    left->push_back(root->val);
    return left;
  }
  std::vector<std::string>* right = _pathFinder(root->right, targetVal);
  if (right != nullptr) {
    right->push_back(root->val);
    return right;
  }
  return nullptr;
}

std::vector<std::string>* pathFinder(Node* root, std::string targetVal) {
  std::vector<std::string>* result = _pathFinder(root, targetVal);
  if (result == nullptr) {
    return nullptr;
  } else {
    std::reverse(result->begin(), result->end());
    return result; 
  }
}




void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}