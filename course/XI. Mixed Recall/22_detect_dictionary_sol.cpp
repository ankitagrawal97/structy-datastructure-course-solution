#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool lexicalOrder(std::string word1, std::string word2, std::string alphabet) {
  for (int i = 0; i < std::max(word1.length(), word2.length()); i += 1) {
    int index1 = std::find(alphabet.begin(), alphabet.end(), word1[i]) - alphabet.begin();
    int index2 = std::find(alphabet.begin(), alphabet.end(), word2[i]) - alphabet.begin();

    int val1 = index1 < alphabet.length() ? index1 : -1;
    int val2 = index2 < alphabet.length() ? index2 : -1;
    
    if (val1 < val2) {
      return true;
    } else if (val2 < val1) {
      return false;
    }
  }
  
  return true;
}
bool detectDictionary(std::vector<std::string> dictionary, std::string alphabet) {
  for(int i = 0; i<dictionary.size()-1;i++){
    string word1 = dictionary[i];
    string word2 = dictionary[i+1];
    
    if(!lexicalOrder(word1,word2,alphabet)){
      return false;
    }
  }
  return true;
}



void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}