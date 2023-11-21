// 53. Maximum Subarray | Nov 20, 2023

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

class Solution {
public:
  int maxSubArray(std::vector<int> &nums) {
    int cur = 0;
    int ans = INT32_MIN;
    for (int x : nums) {
      cur += x;
      ans = std::max(ans, cur);
      cur = std::max(cur, 0);
    }
    return ans;
  }
  /* int maxSubArray(std::vector<int> &nums) {
    int maxSum = INT32_MIN;
    for (int i = 1; i < nums.size(); i++) {
      nums[i] = std::max(nums[i], nums[i] + nums[i-1]);
    }
    for (int x : nums) {
      maxSum = std::max(maxSum, x);
    }
    return maxSum;
  } */
  Solution() {}
};

int main() { Solution(); }
