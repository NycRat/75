// 704. Binary Search | Nov 20, 2023

#include <iostream>
#include <vector>

class Solution {
public:
  int search(std::vector<int> &nums, int target) {
    int low = 0, high = nums.size() - 1;
    while (low < high) {
      int mid = (low + high) / 2;

      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] < target) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    if (nums[low] == target) {
      return low;
    } else {
      return -1;
    }
  }
  Solution() {}
};

int main() { Solution(); }
