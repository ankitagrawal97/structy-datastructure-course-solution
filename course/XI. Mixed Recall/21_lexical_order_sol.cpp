#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

bool lexicalOrder(std::string word1, std::string word2, std::string alphabet) {

  int length = max(word1.length(),word2.length());

  for(int i = 0 ; i < length ; i++){
      //finding index of the letter in the alphabet string 
    int idx1 = find(alphabet.begin(), alphabet.end(), word1[i]) - alphabet.begin();
    int idx2 = find(alphabet.begin(), alphabet.end(), word2[i]) - alphabet.begin();
    //guarding nullptr case
    int val1 = idx1 < alphabet.length() ? idx1 : -1 ;
    int val2 = idx2 < alphabet.length() ? idx2 : -1;
    //comparing
    if(val1 < val2){
      return true;
    }else if(val2 < val1){
      return false;
    }
    
  }
  return true;
}



void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}