#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

int exploreSize(std::vector<std::vector<char>> grid, int row, int col, std::unordered_set<std::string> &visited) {
  bool rowInbounds = 0 <= row && row < grid.size();
  bool colInbounds = 0 <= col && col < grid[0].size(); 
  if (!rowInbounds || !colInbounds) {
    return -1;
  }
  
  if (grid[row][col] == 'W') {
    return -1;
  }
  
  std::string pos = std::to_string(row) + "," + std::to_string(col);
  if (visited.count(pos) > 0) {
    return -1;
  }
  visited.insert(pos);
  
  int totalSize = 1;
  totalSize += std::max(exploreSize(grid, row + 1, col, visited), 0);
  totalSize += std::max(exploreSize(grid, row - 1, col, visited), 0);
  totalSize += std::max(exploreSize(grid, row, col + 1, visited), 0);
  totalSize += std::max(exploreSize(grid, row, col - 1, visited), 0);
  return totalSize;
}

int minimumIsland(std::vector<std::vector<char>> grid) {
  std::unordered_set<std::string> visited;
  int min = 0;
  for (int r = 0; r < grid.size(); r += 1) {
    for (int c = 0; c < grid.size(); c += 1) {
      int islandSize = exploreSize(grid, r, c, visited);
      if (islandSize != -1 && (islandSize < min || min == 0)) {
        min = islandSize;
      }
    }
  }
  return min;
}
void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}