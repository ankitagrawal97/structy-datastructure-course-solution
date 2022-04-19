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



Node* insertNode(Node* head, std::string value, int idx) {
  if(idx==0){ //case : insertion at head
    Node* newNode = new Node(value);
    newNode->next = head;
    return newNode;
  }
  int count = 0;
  Node* curr = head;
  while(curr){
    
    if(count==idx-1){
      //perform insertion
      Node* newNode = new Node(value);
      Node* next = curr->next;
      curr->next = newNode;
      newNode->next = next;
    }
    curr = curr->next;
    count++;
    
    
  }
  return head;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}