// 217. Contains Duplicate | Nov 22, 2023

#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {
public:
  bool containsDuplicate(std::vector<int> &nums) {
    std::unordered_set<int> prev;
    for (int x : nums) {
      if (prev.count(x)) {
        return true;
      }
      prev.insert(x);
    }
    return false;
  }
  Solution() {}
};

int main() { Solution(); }
