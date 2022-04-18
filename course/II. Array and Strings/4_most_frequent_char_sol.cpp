#include <string>
#include <unordered_map>
#include <limits.h>

using namespace std;

char mostFrequentChar(std::string s) {
  unordered_map<char,int> map;
  for(char c : s){
    map[c]++;
  }
  int best = '\0';
  for(int i = 0; i<s.length();i++){
    char current = s[i];
    if(best == '\0' || map[current]>map[best]){
      best = current;
    }
  }
   return best;
}



void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}