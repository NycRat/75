// 3. Longest Substring Without Repeating Characters | Dec 25, 2023

#include <algorithm>
#include <string>
#include <unordered_map>

class Solution {
public:
  int lengthOfLongestSubstring(std::string s) {
    std::unordered_map<char, int> prev;

    int ans = 0;
    int start = 0;
    for (int end = 0; end < s.size(); end++) {
      if (prev.count(s[end])) {
        if (prev[s[end]] >= start) {
          start = prev[s[end]] + 1;
        }
      }
      ans = std::max(ans, end - start + 1);
      prev[s[end]] = end;
    }

    return ans;
  }
  Solution() {}
};

int main() { Solution(); }
