// 973. K Closest Points to Origin | Dec 23, 2023

#include <cmath>
#include <vector>

struct Thingy {
  int i;
  double distance;
};

class Solution {
public:
  std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>> &points,
                                         int k) {
    std::vector<Thingy> ha;
    for (int i = 0; i < points.size(); i++) {
      ha.push_back({i, std::sqrt((double)(points[i][0] * points[i][0] +
                                          points[i][1] * points[i][1]))});
    }
    sort(ha.begin(), ha.end(),
         [](Thingy &a, Thingy &b) { return a.distance > b.distance; });
    std::vector<std::vector<int>> ans;
    for (int i = 0; i < k; i++) {
      ans.push_back(points[ha[i].i]);
    }
    return ans;
  }
  Solution() {}
};

int main() { Solution(); }
