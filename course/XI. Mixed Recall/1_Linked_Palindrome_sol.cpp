#include <vector>
#include <algorithm>

using namespace std;

class Node {
  public:
    int val;
    Node* next;

    Node(int initialVal) {
      val = initialVal;
      next = nullptr;
    }
};


bool linkedPalindrome(Node* head) {
  Node* current = head;
  vector<int> vec;
  while(current){
    vec.push_back(current->val);
    current = current->next;
  }
  //vector<int> reversed = vector<int>(vec.begin(),vec.end());
  vector<int> reversed = vec;
  reverse(reversed.begin(),reversed.end());
  return vec == reversed;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}