#include <string>
#include <vector>

std::string decompressBraces(std::string str) {
  std::string nums = "123456789";
  std::vector<std::string> stack;
  
  for (char ch : str) {
    if (ch == '}') {
      std::string segment = "";
      while (nums.find(stack[stack.size() - 1]) == std::string::npos) {
        segment = stack[stack.size() - 1] + segment;
        stack.pop_back();  
      }
      int num = std::stoi(stack[stack.size() - 1]);
      stack.pop_back();  
      for (int i = 0; i < num; i += 1) {
        stack.push_back(segment);
      }
    } else if (nums.find(ch) != std::string::npos || ch != '{') {
      stack.push_back(std::string(1, ch));  
    }
  }
  
  std::string result = "";
  for (std::string s : stack) {
    result += s;
  }
  
  return result;
}
void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}