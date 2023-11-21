// 383. Ransom Note | Nov 21, 2023

#include <iostream>
#include <unordered_map>

class Solution {
public:
  bool canConstruct(std::string ransomNote, std::string magazine) {
    std::unordered_map<char, int> letter_frequencies;
    for (char c : magazine) {
      letter_frequencies[c]++;
    }
    for (char c : ransomNote) {
      
      if (--letter_frequencies[c] < 0) {
        return false;
      }
    }
    return true;
  }
  Solution() {}
};

int main() { Solution(); }
