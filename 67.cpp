// 67. Add Binary | Nov 23, 2023

#include <iostream>

class Solution {
public:
  std::string addBinary(std::string a, std::string b) {
    std::string &longS = a.size() > b.size() ? a : b;
    std::string &shortS = a.size() > b.size() ? b : a;

    int n = longS.size() - 1;
    int m = shortS.size() - 1;

    int stack = 0;
    for (int i = 0; i < shortS.size(); i++) {
      stack += (longS[n - i] == '1') + (shortS[m - i] == '1');
      longS[n - i] = '0' + stack % 2;
      stack /= 2;
    }
    for (int i = n - m - 1; i >= 0; i--) {
      stack += (longS[i] == '1');
      longS[i] = '0' + stack % 2;
      stack /= 2;
    }
    if (stack) {
      return "1" + longS;
    } else {
      return longS;
    }
  }
  Solution() {
    std::cout << addBinary("11", "1") << std::endl;
    std::cout << addBinary("1010", "1011") << std::endl;
  }
};

int main() { Solution(); }
