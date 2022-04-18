#include <vector>
#include <unordered_set>

std::vector<int> intersection(std::vector<int> a, std::vector<int> b) {
  std::unordered_set<int> setA;
  
  for (int el : a) {
    setA.insert(el);
  }
  
  std::vector<int> result;
  for (int el : b) {
    if (setA.count(el) > 0) {
      result.push_back(el);
    }
  }
  
  return result;
}

void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}