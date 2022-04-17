#include <unordered_map>
#include <string>

using namespace std;

string tokenTransform(string s, unordered_map<string, string> tokens) {
    //making the function recursive and store value in memo
  if(tokens.count(s)){
    return tokens[s];
  }
  string output;
  int i = 0;
  int j = 1;
  
  while(i<s.length()){
    if(s[i] != '$'){
      output += s[i];
      i++;
      j = i + 1;
    }else if(s[j] != '$'){
      j++;
    }else{
      string key = s.substr(i,j-i+1);
      string evaluatedToken = tokenTransform(tokens[key], tokens); //recursive call
      tokens[key] = evaluatedToken; //add the value to map
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