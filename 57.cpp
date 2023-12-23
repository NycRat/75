// 57. Insert Interval | Dec 13, 2023

#include <algorithm>
#include <iostream>
#include <vector>

#define vec std::vector

class Solution {
public:
  vec<vec<int>> insert(vec<vec<int>> &intervals, vec<int> &new_interval) {
    const int start = new_interval[0];
    const int end = new_interval[1];
    const size_t n = intervals.size();

    bool in_between = true;
    size_t pos = -1;

    for (size_t i = 0; i < n; i++) {
      const int cur_start = intervals[i][0];
      const int cur_end = intervals[i][1];
      if (start >= cur_start && start <= cur_end) {
        intervals[i][1] = std::max(cur_end, end);
        pos = i;
        break;
      }
      if (start >= cur_start) {
        in_between = true;
      } else {
        if (in_between) {
          // insert
          intervals.insert(intervals.begin() + i, new_interval);
          pos = i;
          break;
        }
        in_between = false;
      }
    }

    if (pos == -1) {
      intervals.push_back(new_interval);
    } else {
      pos++;
      while (pos < intervals.size()) {
        const int cur_start = intervals[pos][0];
        const int cur_end = intervals[pos][1];
        if (end >= cur_end) {
          intervals.erase(intervals.begin() + pos);
          continue;
        } else if (end >= cur_start) {
          intervals[pos - 1][1] = cur_end;
          intervals.erase(intervals.begin() + pos);
        }
        break;
      }
    }

    return intervals;
  }
  Solution() {
    {
      vec<vec<int>> thing = {{1, 5}};
      vec<int> thing2 = {2, 3};
      auto ans = insert(thing, thing2);
      for (auto &a : ans) {
        std::cout << a[0] << " " << a[1] << std::endl;
      }
    }
    {
      vec<vec<int>> thing = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
      vec<int> thing2 = {4, 8};
      auto ans = insert(thing, thing2);
      for (auto &a : ans) {
        std::cout << a[0] << " " << a[1] << std::endl;
      }
    }
  }
};

int main() { Solution(); }
