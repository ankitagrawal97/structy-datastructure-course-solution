#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

bool compareIntervals(tuple<int, int> a, tuple<int, int> b){
  auto [aStart, aEnd] = a;
  auto [bStart, bEnd] = b;
  return aStart < bStart;
}

std::vector<std::tuple<int, int>> combineIntervals(std::vector<std::tuple<int, int>> intervals) {
  std::sort(intervals.begin(), intervals.end(), compareIntervals);
  std::vector<std::tuple<int, int>> newIntervals{ intervals[0] };
  
  for (int i = 1; i < intervals.size(); i += 1) {
    std::tuple<int, int> currentInterval = intervals[i];
    auto [currentStart, currentEnd] = currentInterval;
    auto [lastStart, lastEnd] = newIntervals[newIntervals.size() - 1];
    if (currentStart <= lastEnd) {
      if (currentEnd > lastEnd) {
        newIntervals[newIntervals.size() - 1] = { lastStart, currentEnd };
      }
    } else {
      newIntervals.push_back({ currentStart, currentEnd });
    }
  }
  
  return newIntervals;
}



void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}