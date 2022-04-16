#include <math.h>
#include <vector>

using namespace std;


int binarySearch(std::vector<int> numbers, int target) {

  int low = 0;
  int high = numbers.size()-1;
  while(low<=high){
    int mid = floor((high+low)/2);
      if(numbers[mid]==target){
      return mid;
      }else if(numbers[mid]<target){
      low = mid + 1;
      }else{
      high = mid - 1;
      }
  }
  return -1;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}