#include <string>
#include <unordered_map>
using namespace std;

unordered_map<char,int> charCount(string s1){
  unordered_map<char,int> map;
  for(auto c : s1){
    map[c]++;
  }
  return map;
}


bool anagrams(string s1, string s2) {
  return charCount(s1) == charCount(s2);
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}