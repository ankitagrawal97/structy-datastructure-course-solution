#include <math.h>
#include <unordered_map>
using namespace std;

int summingSquares(int n, unordered_map<int,int> &memo) {
  if(memo.count(n) > 0){
    return memo[n];
  }
  if(n==0){
    return 0;
  }
  int min = 0;
  for(int i = 1 ; i <= sqrt(n) ; i++ ){
    int remainder = n - (i*i);
    int squares = 1 + summingSquares(remainder,memo);
    if(min == 0 || squares < min){
      min = squares;
      
    }
  }
  memo[n] = min;
  return min;
}
int summingSquares(int n) {
  unordered_map<int,int> memo;  
  return summingSquares(n,memo);
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}