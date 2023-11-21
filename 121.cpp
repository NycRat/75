// 121. Best Time to Buy and Sell Stock | Nov 19, 2023

#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  int maxProfit(std::vector<int> &prices) {
    int low = prices[0];
    int maxProf = 0;
    for (int p : prices) {
      low = std::min(low, p);
      maxProf = std::max(maxProf, p - low);
    }
    return maxProf;
  }
  Solution() {}
};

int main() { Solution(); }
