// 125. Valid Palindrome | Nov 19, 2023

#include <cctype>
#include <cstddef>
#include <iostream>
#include <string>

class Solution {
public:
  bool isPalindrome(std::string s) {
    size_t low = 0, high = s.length() - 1;
    while (low < high) {
      if (!std::isalnum(s[low])) {
        low++;
      } else if (!std::isalnum(s[high])) {
        high--;
      } else {

        if (std::tolower(s[low]) != std::tolower(s[high])) {
          return false;
        }
        low++;
        high--;
      }
    }
    return true;
  }
  Solution() {}
};

int main() { Solution(); }
