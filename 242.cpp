// 242. Valid Anagram | Nov 20, 2023

#include <iostream>
#include <unordered_map>

class Solution {
public:
  bool isAnagram(std::string s, std::string t) {
    if (s.length() != t.length()) {
      return false;
    }
    std::unordered_map<char, int> letter_frequencies;
    for (int i = 0; i < s.length(); i++) {
      letter_frequencies[s[i]]++;
      letter_frequencies[t[i]]--;
    }
    for (auto &[_, amount] : letter_frequencies) {
      if (amount) {
        return false;
      }
    }
    return true;
  }
  Solution() {}
};

int main() { Solution(); }
