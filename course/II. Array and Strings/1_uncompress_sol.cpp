#include <string>
using namespace std;

string uncompress(string s) {
  string result = "";
  string numbers = "1234567890";
  int i = 0;
  int j = 0;
  while(j<s.length()){
      //keep iterating untill s[j] is a number
    if(numbers.find(s[j]) != string::npos ){
      j++;
    }else{
        //capture the number
      int num = stoi(s.substr(i,j)); // j is exclusive the method substr()
      //make string and add into the result 
      result += string(num,s[j]);
      //set indices for next iteration
      j++;
      i = j;
    }
  }
  return result;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}