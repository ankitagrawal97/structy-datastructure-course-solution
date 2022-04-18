#include <string>

class Node {
  public:
    std::string val;
    Node* next;

    Node(std::string initialVal) {
      val = initialVal;
      next = nullptr;
    }
};



Node* zipperLists(Node* head1, Node* head2) {
  Node* dummyhead = head1;
  Node* tail = dummyhead;
  
  Node* current1 = head1->next;
  Node* current2 = head2;
  
  int count = 1;
  while (current1 != nullptr && current2 != nullptr) {
    if (count % 2 == 0) { //when count is even nodes from 1st list
      tail->next = current1;
      current1 = current1->next;
    } else {
      tail->next = current2;//when count is odd nodes from 2nd list
      current2 = current2->next;
    }
    
    tail = tail->next;
    count += 1;
  }
  
  if (current1 != nullptr) {//if list2 runs out before list1 
    tail->next = current1;
  }
  if (current2 != nullptr) {//if list1 runs out before list2
    tail->next = current2;
  }
  
  return dummyhead;
}

void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}