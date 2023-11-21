// 70. Climbing Stairs | Nov 21, 2023

#include <iostream>

class Solution {
public:
  int dp[100];
  int climbStairs(int n) {
    if (n < 0) {
      return 0;
    }
    if (n <= 1) {
      return 1;
    }
    if (dp[n] != 0) {
      return dp[n];
    } else {
      dp[n] = climbStairs(n - 1) + climbStairs(n - 2);
      return dp[n];
    }
    // (0) = 0
    // (1) = 1
    // 1
    // (2) = 2
    // 1 + (1)
    // 2 + (0)
    // (3) =
    // 1 + (2)
    // 2 + (1)
    //
  }
  Solution() {}
};

int main() { Solution(); }
