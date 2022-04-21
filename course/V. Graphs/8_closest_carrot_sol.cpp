#include <vector>
#include <queue>
#include <tuple>
#include <string>
#include <unordered_set>

using namespace std;

int closestCarrot(std::vector<std::vector<char>> grid, int startRow, int startCol) {
  queue<tuple<int,int,int>> queue;
  unordered_set<string> visited;
  queue.push(tuple<int,int,int>{startRow,startCol,0});
  visited.insert(to_string(startRow)+","+to_string(startCol));
  
  while(queue.size()){
    auto [currrow,currcol,distance] = queue.front();
    queue.pop();
    
    if(grid[currrow][currcol] == 'C'){
      return distance;
    }
    vector<tuple<int,int>> deltas = {{1,0},{0,1},{-1,0},{0,-1}};
    for(auto delta : deltas){
      auto [dRow,dCol] = delta;
      int neighbourRow = currrow + dRow;
      int neighbourCol = currcol + dCol;
      string pos = to_string(neighbourRow)+","+to_string(neighbourCol);
      bool rowInbounds = 0 <= neighbourRow && neighbourRow < grid.size();
      bool colInbounds = 0 <= neighbourCol && neighbourCol < grid[0].size();
      if(rowInbounds && colInbounds && grid[neighbourRow][neighbourCol] != 'X' && visited.count(pos)==0){
        visited.insert(pos);
        queue.push(tuple<int,int,int>{neighbourRow,neighbourCol,distance+1});
      }
    }
  }
  
  return -1;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}