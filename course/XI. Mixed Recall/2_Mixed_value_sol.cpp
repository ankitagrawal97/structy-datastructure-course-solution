#include <string>
#include <vector>
#include <math.h>
class Node {
  public:
    std::string val;
    Node* next;

    Node(std::string initialVal) {
      val = initialVal;
      next = nullptr;
    }
};


std::string middleValue(Node* head) {
  std::vector<std::string> values;
  Node* current = head;
  while (current != nullptr) {
    values.push_back(current->val);
    current = current->next;
  }
  return values[std::floor(values.size() / 2)];
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}