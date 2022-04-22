#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

int maxPathSum(vector<vector<int>> grid, int r, int c, unordered_map<string,int> &memo){
  string pos = to_string(r)+","+to_string(c);
  if(memo.count(pos)){
    return memo[pos];
  }
  bool rBound = 0 <= r && r < grid.size();
  bool cBound = 0 <= c && c < grid[0].size();
  
  if(!rBound || !cBound){
    return 0;
  }
  if(r==grid.size()-1 && c == grid[0].size()-1){
    return grid[r][c];
  }
  
  memo[pos] = grid[r][c] + max(maxPathSum(grid,r+1,c,memo) , maxPathSum(grid,r,c+1,memo)); 
  return memo[pos];
}

int maxPathSum(std::vector<std::vector<int>> grid) {
unordered_map<string,int> memo;  
  return maxPathSum(grid,0,0,memo);
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}