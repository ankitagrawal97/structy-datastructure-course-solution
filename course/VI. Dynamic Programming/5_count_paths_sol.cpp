#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int countPaths(vector<vector<char>> grid, int r , int c, unordered_map<string,int> &memo){
  string pos = to_string(r)+","+to_string(c);
  if(memo.count(pos)){
    return memo[pos];
  }
  bool rBound = 0 <= r && r < grid.size();
  bool cBound = 0 <= c && c < grid[1].size();
  if(!rBound || !cBound || grid[r][c] == 'X'){
    return 0;
  }
  if(r == grid.size()-1 && c == grid[0].size()-1){
    return 1;
  }
  memo[pos] = countPaths(grid,r+1,c,memo) + countPaths(grid,r,c+1,memo);
  return memo[pos];
}

int countPaths(std::vector<std::vector<char>> grid) {

  unordered_map<string,int> memo;
  
  return countPaths(grid,0,0,memo);
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}