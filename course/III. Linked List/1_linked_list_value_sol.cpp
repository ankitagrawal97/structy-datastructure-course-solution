#include <vector>
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



std::vector<std::string> linkedListValues(Node* head) {
  vector<string> result;
  if(!head){
    return result;
  }
  Node* current = head;
  while(current){
    result.push_back(current->val);
    current = current->next;
  }
  return result; 
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}