// 20. Valid Parentheses | Nov 19, 2023

#include <iostream>
#include <stack>

class Solution {
public:
  bool isValid(std::string s) {
    std::stack<char> prev;

    for (char c : s) {
      if (c == ')' || c == ']' || c == '}') {
        if (prev.empty()) {
          return false;
        }
        if (c == ')') {
          if (prev.top() != '(') {
            return false;
          }
        } else if (c == ']') {
          if (prev.top() != '[') {
            return false;
          }
        } else if (c == '}') {
          if (prev.top() != '{') {
            return false;
          }
        }
        prev.pop();
      } else {
        prev.push(c);
      }
    }

    return prev.empty();
  }
  Solution() {}
};

int main() { Solution(); }
