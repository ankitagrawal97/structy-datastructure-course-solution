#include <array>
#include <vector>
#include <unordered_map>
std::array<int, 2> pairProduct(std::vector<int> numbers, int target) {
  std::unordered_map<int, int> divisor;
  for (int i = 0; i < numbers.size(); i += 1) {
    int div = target/numbers[i];
    if (divisor.count(div) > 0) {
      return std::array<int, 2> { i, divisor[div] };
    }
    divisor[numbers[i]] = i;
  }
  
}

void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}