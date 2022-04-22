#include <string>
#include <stack>
using namespace std;

bool pairedParentheses(string str) {
  stack<char> stac;
  for ( char c : str){
    if(c == '('){
      stac.push(c);
    }else if(c == ')' && !stac.empty()){
      stac.pop();
    }else if(c == ')' && stac.empty()){
      return false;
    }
  }
  
  return stac.empty();
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}