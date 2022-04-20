#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

string stringyfy(int r , int c){ //helper function to store visited indexes
  return to_string(r)+","+to_string(c);
}

bool explore(std::vector<std::vector<char>> grid, unordered_set<string> &visited,int r, int c){
  bool rowBound = 0 <= r && r < grid.size();
  bool colBound = 0 <= c && c < grid[0].size();
  
  if(!rowBound || !colBound){ //check in if r,c are inbound
    return false;
  }
  
  if(grid[r][c]=='W'){ //if r,c is water
    return false;
  }
  
  string pos = stringyfy(r,c);
  if(visited.count(pos)){
    return false;
  }
  visited.insert(pos);
  
  explore(grid,visited,r+1,c);
  explore(grid,visited,r,c+1);
  explore(grid,visited,r-1,c);
  explore(grid,visited,r,c-1);
  
  return true;
}

int islandCount(std::vector<std::vector<char>> grid) {
  int count = 0;
  unordered_set<string> visited;
  for(int r = 0 ; r < grid.size() ; r++){
  for(int c = 0 ; c < grid[0].size();c++){
    if(explore(grid,visited,r,c)){ //if is a island
      count++;
    }
  }
  }
  return count;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}