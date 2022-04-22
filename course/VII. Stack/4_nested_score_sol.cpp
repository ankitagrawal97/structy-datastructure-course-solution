#include <string>
#include <stack>
using namespace std;
int nestingScore(std::string str) {
  stack<int> stac;
  stac.push(0);
  for(char c : str){
    if(c == '['){
      stac.push(0);
    }else{
        int popped = stac.top();
        stac.pop();
        if(popped==0){
         stac.top()++;
        }else{
           stac.top() +=  2*popped;    
        }
    }
  }
  return stac.top();
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}