#include <string>
#include <vector>
using namespace std;

class Node {
  public:
    std::string val;
    Node* next;

    Node(std::string initialVal) {
      val = initialVal;
      next = nullptr;
    }
};



Node* createLinkedList(std::vector<std::string> values) {
  Node* dummyHead = new Node("");
  Node* tail = dummyHead;
  
  for (std::string val : values) {
    tail->next = new Node(val);
    tail = tail->next;
  }
  
  return dummyHead->next;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}