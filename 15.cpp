// 15. 3Sum | Dec 2, 2023

#include <algorithm>
#include <set>
#include <unordered_map>
#include <utility>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
    std::vector<std::vector<int>> ans;
    std::unordered_map<int, std::set<std::pair<int, int>>> sums_and_indices;
    std::set<std::vector<int>> haa;

    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        sums_and_indices[nums[i] + nums[j]].insert(std::make_pair(i, j));
      }
    }

    for (int i = 0; i < nums.size(); i++) {
      if (sums_and_indices.count(-nums[i])) {
        auto &works = sums_and_indices[-nums[i]];
        for (auto &[a, b] : works) {
          if (a != i && b != i) {
            std::vector<int> wha = {nums[i], nums[a], nums[b]};
            sort(wha.begin(), wha.end());
            haa.insert(wha);
          }
        }
      }
    }
    for (auto&x : haa) {
      ans.push_back(x);
    }

    return ans;
  }
  Solution() {}
};

int main() { Solution(); }
