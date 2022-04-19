class Node {
  public:
    int val;
    Node* next;

    Node(int initialVal) {
      val = initialVal;
      next = nullptr;
    }
};



bool isUnivalueList(Node* head) {
  Node* curr = head;
  while(curr){
    if(curr->val!=head->val){
      return false;
    }
    curr = curr->next;
  }
  return true;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}