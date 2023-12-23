// 13. Roman to Integer | Nov 22, 2023

#include <iostream>

class Solution {
public:
  int romanNumToInt(char c) {
    switch (c) {
    case 'I':
      return 1;
    case 'V':
      return 5;
    case 'X':
      return 10;
    case 'L':
      return 50;
    case 'C':
      return 100;
    case 'D':
      return 500;
    case 'M':
      return 1000;
    }
    return -1;
  }
  int romanToInt(std::string s) {
    int ans = 0;
    int last = 0;
    int cur = 0;
    for (char c : s) {
      int rightnow = romanNumToInt(c);
      if (rightnow > last) {
        // IX
        // 1
        // 9
        cur = rightnow - cur;
      } else if (rightnow < last) {
        ans += cur;
        cur = rightnow;
      } else {
        cur += rightnow;
      }
      last = rightnow;
    }
    ans += cur;
    return ans;
  }
  Solution() {
    std::cout << romanToInt("III") << std::endl;
    std::cout << romanToInt("LVIII") << std::endl;
    std::cout << romanToInt("MCMXCIV") << std::endl;
  }
};

int main() { Solution(); }
