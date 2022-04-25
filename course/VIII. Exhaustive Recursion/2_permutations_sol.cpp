#include <vector>
#include <string>
using namespace std;

vector<vector<string>> permutations(vector<string> elements) {

  if(elements.size()==0){
    return vector<vector<string>> { { } };
  }
  string elem = elements[0]; //grabbing the first element
  //creating a copy of the vectors without the elem
  vector<vector<string>> permswithout = permutations(vector<string>(elements.begin()+1,elements.end()));

  vector<vector<string>> result; //initializing an empty vector to store final result
  
  for(vector<string> without : permswithout){
    for(int i = 0 ; i <= without.size(); i++){
      //creating a duplicate of the without vector.
      vector<string> with = vector<string>(without.begin() ,without.end());
     //inserting the elem at every position in every interation
      with.insert(with.begin() + i,elem);
      //pushing the final vector after each iteration in the result vector
      result.push_back(with);
    }
  }
  
  return result;
}

void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}