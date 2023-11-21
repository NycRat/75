// 733. Flood Fill | Nov 20, 2023

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>> &image,
                                          int sr, int sc, int color) {
    int cur = image[sr][sc];
    if (cur == color) {
      return image;
    }
    image[sr][sc] = color;
    if (sr - 1 >= 0 && image[sr - 1][sc] == cur) {
      floodFill(image, sr - 1, sc, color);
    }
    if (sc - 1 >= 0 && image[sr][sc - 1] == cur) {
      floodFill(image, sr, sc - 1, color);
    }
    if (sr + 1 < image.size() && image[sr + 1][sc] == cur) {
      floodFill(image, sr + 1, sc, color);
    }
    if (sc + 1 < image[0].size() && image[sr][sc + 1] == cur) {
      floodFill(image, sr, sc + 1, color);
    }

    return image;
  }
  Solution() {}
};

int main() { Solution(); }
