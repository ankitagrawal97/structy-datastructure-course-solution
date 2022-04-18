class Node {
  public:
    int val;
    Node* next;

    Node(int initialVal) {
      val = initialVal;
      next = nullptr;
    }
};


/*
//iterative solution , O(1) space complexity
Node* mergeLists(Node* head1, Node* head2) {
  Node dummyHead(0);
  Node* tail = &dummyHead;
  
  Node* current1 = head1;
  Node* current2 = head2;
  while (current1 != nullptr and current2 != nullptr) {
    if (current1->val < current2->val) {
      tail->next = current1;
      current1 = current1->next;
    } else {
      tail->next = current2;
      current2 = current2->next;
    }
    tail = tail->next;
  }
  
  if (current1 != nullptr) {
    tail->next = current1;
  }
  if (current2 != nullptr) {
    tail->next = current2;
  }
  
  return dummyHead.next;
}
*/
//rescurive solution O(min(n,m)) complexity
Node* mergeLists(Node* head1, Node* head2) {
  if(!head1){
    return head2;
  }
  if(!head2){
    return head1;
  }
  if(head1->val<head2->val){
    head1->next=mergeLists(head1->next,head2);
    return head1;
  }else{
    head2->next = mergeLists(head1,head2->next);
    return head2;
  }
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}