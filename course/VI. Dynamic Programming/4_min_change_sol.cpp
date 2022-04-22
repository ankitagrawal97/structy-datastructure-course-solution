#include <vector>
#include <unordered_map>

using namespace std;

int minChange(int amount,vector<int> coins,unordered_map<int,int> &memo){
  if(memo.count(amount)){
    return memo[amount];
  }
  if(amount == 0){
    return 0;
  }
  if(amount < 0){
    return -1;
  }
  int min = -1;
  for(auto coin : coins){
    int remainder = amount - coin;
    int remainderqty  = minChange(remainder,coins,memo);
    if(remainderqty!=-1){
      int totalqty = remainderqty + 1;
      if(min == -1 || totalqty < min){
        min = totalqty;
      }
    }
  }
  memo[amount] = min;
  return min;
}


int minChange(int amount, std::vector<int> coins) {

  unordered_map<int,int> memo;
  return minChange(amount,coins,memo);
  
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}