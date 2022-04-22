#include <vector>
#include <unordered_map>
#include <algorithm>

int nonAdjacentSum(std::vector<int> nums, int i, std::unordered_map<int, int> &memo) {
  if (memo.count(i) > 0) {
    return memo[i];
  }
  
  if (i >= nums.size()) {
    return 0;
  }
  
  int take = nums[i] + nonAdjacentSum(nums, i + 2, memo);
  int skip = nonAdjacentSum(nums, i + 1, memo);
  memo[i] = std::max(take, skip);
  return memo[i];
}

int nonAdjacentSum(std::vector<int> nums) {
  std::unordered_map<int, int> memo;
  return nonAdjacentSum(nums, 0, memo); 
}

void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}