#include <unordered_map>
#include <string>

using namespace std;

string tokenReplace(string s, unordered_map<string, string> tokens) {
    //using two pointer approach to capture token and then replace it
  string output;
  int i = 0;
  int j = 1;
  while(i<s.length()){
    if(s[i] != '$'){
      output += s[i];
      i++;
      j =i+1;
    }else if(s[j] != '$'){
      j++;
    }else{
      string key = s.substr(i,j-i+1);
      output += tokens[key];
      i = j + 1;
      j = i + 1;
    }
  }
  return output;
}

void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}