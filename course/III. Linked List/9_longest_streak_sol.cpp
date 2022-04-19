#include<algorithm>

class Node {
  public:
    int val;
    Node* next;

    Node(int initialVal) {
      val = initialVal;
      next = nullptr;
    }
};



int longestStreak(Node* head) {
  
  int count = 0;
  int best = 0;
  
  Node* prev = nullptr;
  Node* curr = head;
  
  while(curr){
    if(prev == nullptr || prev->val == curr->val){
      count++;   
    }else{
      count = 1;
    }
    best = std::max(count,best);
    prev = curr;
    curr = curr->next;
  }
  return best;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}