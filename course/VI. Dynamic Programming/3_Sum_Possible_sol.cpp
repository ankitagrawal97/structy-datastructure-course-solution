#include <vector>
#include <unordered_map>
using namespace std;

bool sumPossible(int amount, vector<int> numbers, unordered_map<int,bool> &memo){
  if(memo.count(amount)>0){
    return memo[amount];
  }
  if(amount == 0){
    return true;
  }
  if(amount<0){
    return false;
  }
  for(int num : numbers){
    if(sumPossible(amount-num,numbers,memo)){
      memo[amount] = true;
      return true;
    }
  }
  memo[amount] = false;
  return false;
  
}


bool sumPossible(int amount, std::vector<int> numbers) {
  unordered_map<int,bool> memo;
  return sumPossible(amount,numbers,memo);
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}