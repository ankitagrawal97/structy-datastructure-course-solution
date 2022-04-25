#include <vector>
#include <string>
using namespace std;

vector<vector<string>> createCombinations(vector<string> items, int size) {
  if(size == 0){
    return vector<vector<string>> { { } };
  }
  if(size>items.size()){
    return vector<vector<string>> { };
  }
  string ele = items[0];
  vector<string> remaining = vector<string>(items.begin()+1,items.end());
  vector<vector<string>> result;
  
  for(auto comb : createCombinations(remaining,size)){
    result.push_back(comb);
  }
  for(auto comb : createCombinations(remaining,size-1)){
    comb.push_back(ele);
    result.push_back(comb);
  }
  
  return result;
}

void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}