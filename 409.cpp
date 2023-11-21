// 409. Longest Palindrome | Nov 21, 2023

#include <iostream>

class Solution {
public:
  int letter_frequencies[52];
  int longestPalindrome(std::string s) {
    for (char c : s) {
      if (c >= 'a' && c <= 'z') {
        letter_frequencies[c - 'a']++;
      } else {
        letter_frequencies[c - 'A' + 26]++;
      }
    }

    int ans = 0;
    bool thingy = false;

    for (int x : letter_frequencies) {
      ans += x - x % 2;
      thingy = thingy || (x % 2);
    }

    return ans + thingy;
  }
  Solution() {}
};

int main() { Solution(); }
