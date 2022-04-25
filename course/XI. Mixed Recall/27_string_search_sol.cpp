#include <vector>
#include <string>
#include <unordered_set>

bool dfs(std::vector<std::vector<char>> grid, std::string target,int idx, int r, int c) {
  if (idx == target.length()) {
    return true;
  }
  
  if (r < 0 || r >= grid.size() || c < 0 || r >= grid[0].size()) {
    return false;
  }
  
  if (grid[r][c] == '*' || grid[r][c] != target[idx]) {
    return false;
  }
  char orgChar = grid[r][c];
  grid[r][c] = '*';//logic to keep track of visited
  
  bool result = dfs(grid, target, idx+1, r - 1, c) || 
    dfs(grid, target,idx+1, r + 1, c) || 
    dfs(grid, target,idx+1, r, c - 1) || 
    dfs(grid, target,idx+1, r, c + 1);
    
  grid[r][c] = orgChar;
  
  return result;
}

bool stringSearch(std::vector<std::vector<char>> grid, std::string target) {
  for (int i = 0; i < grid.size(); i += 1) {
    for (int j = 0; j < grid.size(); j += 1) {
      if (dfs(grid, target,0, i, j)) {
        return true;
      }
    }
  }
  return false;
}
void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}