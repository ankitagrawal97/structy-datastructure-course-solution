#include <string>
using namespace std;

string compress(string s) {
  string numbers = "1234567890";
  int i = 0;
  int j = 0;
  string result = "";
  while(j<=s.length()){
    if(s[i] == s[j]){
      j++;
    }else{
      int count = j - i;
      if(count!=1){
        result = result + to_string(count) + s[i];
      }else{
        result += s[i];
      }
      i = j;
    }
    
  }
  return result;
}

void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}