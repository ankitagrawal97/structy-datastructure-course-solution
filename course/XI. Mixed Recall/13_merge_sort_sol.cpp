#include <vector>
#include <math.h>
using namespace std;

vector<int> merge(vector<int> v1,vector<int> v2){
  int i = 0;
  int j = 0;
  vector<int> result;
  while(i<v1.size() && j<v2.size()){
    if(v1[i]<v2[j]){
      result.push_back(v1[i]);
      i++;
    }else{
      result.push_back(v2[j]);
      j++;
    }
  }
  while(i<v1.size()){
    result.push_back(v1[i]);
    i++;
  }
  while(j<v2.size()){
    result.push_back(v2[j]);
    j++;
  }
  return result;
}

vector<int> mergeSort(vector<int> numbers) {
  if(numbers.size()<=1){
    return numbers;
  }
  int midIndex = floor(numbers.size()/2);
  vector<int> leftVector = vector<int>(numbers.begin(),numbers.begin()+midIndex);
  vector<int> rightVector = vector<int>(numbers.begin()+midIndex,numbers.end());
  vector<int> sortedleft = mergeSort(leftVector);
  vector<int> sortedright = mergeSort(rightVector);
  return merge(sortedleft,sortedright);
}



void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}