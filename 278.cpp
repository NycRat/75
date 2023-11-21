// 278. First Bad Version | Nov 21, 2023

#include <iostream>

class Solution {
public:
  bool isBadVersion(int version);
  int firstBadVersion(int n) {
    // 1 2 3 (bad 2)
    // 1 | 3
    // 1 1
    // 
    int low = 1, high = n;
    while (low <= high) {
      int mid = (high - low) / 2 + low;
      if (isBadVersion(mid)) {
        high = mid-1;
      } else {
        low = mid+1;
      }
    }
    return std::max(low, high);
  }
  Solution() {}
};

int main() { Solution(); }
