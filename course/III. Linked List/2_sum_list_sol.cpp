class Node {
  public:
    int val;
    Node* next;

    Node(int initialVal) {
      val = initialVal;
      next = nullptr;
    }
};



int sumList(Node* head) {
  int sum = 0;
  if(!head){
    return sum;
  }
  Node* curr = head;
  while(curr){
    sum += curr->val;
    curr = curr->next;
  }
  return sum;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}