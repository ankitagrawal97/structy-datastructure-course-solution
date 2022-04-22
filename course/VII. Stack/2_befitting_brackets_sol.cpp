#include <string>
#include <stack>
using namespace std;
bool befittingBrackets(std::string str) {
  stack<char> stac;
        for (char c : str){
            switch(c){
                case '(':stac.push(c);break;
                case '{':stac.push(c);break;
                case '[': stac.push(c);break;
                case ')':{
                    if(stac.empty() || stac.top()!='('){
                        return false;
                    }else{
                        stac.pop();
                    }
                    break;
                }
                case '}':{
                    if(stac.empty() || stac.top()!='{'){
                        return false;
                    }else{
                        stac.pop();
                    }
                    break;
                }
                case ']':{
                    if(stac.empty() || stac.top()!='['){
                        return false;
                    }else{
                        stac.pop();
                    }
                    break;
                }
                default:;                           
            }
        }
        
        return stac.empty();
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}