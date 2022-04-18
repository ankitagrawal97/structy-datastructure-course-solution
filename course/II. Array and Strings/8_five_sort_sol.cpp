#include <vector>
using namespace std;

std::vector<int>& fiveSort(std::vector<int> &numbers) {
  int i = 0;
  int j = numbers.size()-1;
  while(i<j){
    if(numbers[i]!=5){
      i++;
    }else if(numbers[j]==5){
      j--;
    }else{
      int temp = numbers[i];
      numbers[i] = numbers[j];
      numbers[j] = temp;
    }
    
  }
  return numbers;
}

void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}