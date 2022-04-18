#include <math.h>


bool isPrime(int n) {
  if(n<2)
    return false;
  for(int i = 2; i <= sqrt(n) ; i++){
    if(n % i == 0){
      return false;
    }
  }
  return true;
}



void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}