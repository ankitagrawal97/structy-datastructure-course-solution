#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

std::vector<std::string> split(std::string sentence) {
  std::stringstream ss(sentence);
  std::string word;
  std::vector<std::string> words;
  while (ss >> word) {
    words.push_back(word);
  }
  return words;
}

std::string join(std::vector<std::string> words) {
  std::string s = "";
  for (int i = 0; i < words.size(); i += 1) {
    std::string word = words[i];
    s += word;
    
    if (i != words.size() - 1) {
      s += ' ';
    }
  }
  return s;
}

std::vector<std::vector<std::string>> substituteSynonyms(std::vector<std::string> words, std::unordered_map<std::string, std::vector<std::string>> synonyms) {
  if (words.size() == 0) {
    return std::vector<std::vector<std::string>> { {} };
  }
  
  std::string currentWord = words[0];
  
  std::vector<std::string> remainingWords = std::vector<std::string>(words.begin() + 1, words.end());
  std::vector<std::vector<std::string>> without = substituteSynonyms(remainingWords, synonyms);
  std::vector<std::vector<std::string>> result;
  
  if (synonyms.count(currentWord) == 0) {
    for (std::vector<std::string> subvector : without) {
      subvector.insert(subvector.begin(), currentWord);
      result.push_back(subvector);
    }
  } else {
    for (std::string synonym : synonyms[currentWord]) {
      for (std::vector<std::string> subvector : without) {
        std::vector<std::string> copy = std::vector<std::string>(subvector.begin(), subvector.end());
        copy.insert(copy.begin(), synonym);
        result.push_back(copy);
      }
    }
  }
  return result;
}

std::vector<std::string> substituteSynonyms(std::string sentence, std::unordered_map<std::string, std::vector<std::string>> synonyms) {
  std::vector<std::string> words = split(sentence);
  std::vector<std::vector<std::string>> vectors = substituteSynonyms(words, synonyms);
  
  std::vector<std::string> finalSentences;
  for (std::vector<std::string> words : vectors) {
    finalSentences.push_back(join(words));
  }
  return finalSentences;
}
void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}