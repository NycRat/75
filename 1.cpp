// 1. Two Sum | Nov 19, 2023

#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<int> twoSum(std::vector<int> &nums, int target) {
    std::unordered_map<int, int> prev;
    for (int i = 0; i < nums.size(); i++) {
      if (prev.count(target - nums[i])) {
        return {prev[target - nums[i]], i};
      }
      prev[nums[i]] = i;
    }
    return {0, 1};
  }
  Solution() {}
};

int main() { Solution(); }
