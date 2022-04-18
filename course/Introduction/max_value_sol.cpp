#include <vector>
#include <limits.h>

float maxValue(std::vector<float> numbers) {
  float min  = INT_MIN;
  for(auto c : numbers){
    if(c>min){
      min = c;
    }
  }
  return min;
}

void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}