#include <vector>
#include <string>
using namespace std;

vector<vector<string>> subsets(vector<string> elements) {
  if(elements.size()==0){
    return vector<vector<string>> { { } };
  }
  string ele = elements[0];
  vector<vector<string>> without = subsets(vector<string>(elements.begin()+1,elements.end()));
  vector<vector<string>> result;
  for(auto subset : without){
    result.push_back(subset);
    
    vector<string> with = vector<string>(subset.begin(),subset.end());
    with.push_back(ele);
    result.push_back(with);
  }
  return result;
}

void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}