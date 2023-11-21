// 844. Backspace String Compare | Nov 20, 2023

#include <iostream>
#include <stack>

class Solution {
public:
  bool backspaceCompare(std::string s, std::string t) {
    int deleteCountS = 0, deleteCountT = 0;
    int iS = s.size() - 1, iT = t.size() - 1;
    while (iS >= 0 || iT >= 0) {
      char cS = iS >= 0 ? s[iS] : -1;
      char cT = iT >= 0 ? t[iT] : -2;
      if (cS == '#') {
        deleteCountS++;
        iS--;
      } else if (cT == '#') {
        deleteCountT++;
        iT--;
      } else if (deleteCountS > 0) {
        deleteCountS--;
        iS--;
      } else if (deleteCountT > 0) {
        deleteCountT--;
        iT--;
      } else if (cS == cT) {
        iT--;
        iS--;
      } else {
        return false;
      }
    }
    return true;
  }
  // bool backspaceCompare(std::string s, std::string t) {
  //   std::stack<char> sFinal;
  //   std::stack<char> tFinal;
  //   for (int i = 0; i < s.size(); i++) {
  //     if (s[i] == '#') {
  //       if (sFinal.size()) {
  //         sFinal.pop();
  //       }
  //
  //     } else {
  //       sFinal.push(s[i]);
  //     }
  //   }
  //   for (int i = 0; i < t.size(); i++) {
  //     if (t[i] == '#') {
  //       if (tFinal.size()) {
  //         tFinal.pop();
  //       }
  //     } else {
  //       tFinal.push(t[i]);
  //     }
  //   }
  //   if (sFinal.size() != tFinal.size()) {
  //     return false;
  //   }
  //   while (sFinal.size()) {
  //     if (sFinal.top() != tFinal.top()) {
  //       return false;
  //     }
  //     sFinal.pop();
  //     tFinal.pop();
  //   }
  //   return true;
  // }
  Solution() {}
};

int main() { Solution(); }
