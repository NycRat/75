// 169. Majority Element | Nov 21, 2023

#include <iostream>
#include <vector>

class Solution {
public:
  int majorityElement(std::vector<int> &nums) {
    int count = 0;
    int candidate = 0;

    for (int num : nums) {
      if (count == 0) {
        candidate = num;
      }

      if (num == candidate) {
        count++;
      } else {
        count--;
      }
    }

    return candidate;
  }
  Solution() {}
};

int main() { Solution(); }
