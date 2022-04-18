#include <string>
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



std::string getNodeValue(Node* head, int idx) {
  int count = 0;
  Node* curr = head;
  while(curr){
    if(count==idx){
      return curr->val;
    }
    curr = curr->next;
    count++;
  }
  return "";
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}