// 542. 01 Matrix | Dec 23, 2023

#include <queue>
#include <vector>

struct Thingy {
  int i, j, distance;
};

class Solution {
public:
  std::vector<std::vector<int>>
  updateMatrix(std::vector<std::vector<int>> &mat) {
    for (auto &vec : mat) {
      for (auto &x : vec) {
        x = -x;
      }
    }

    std::queue<Thingy> q;
    for (int i = 0; i < mat.size(); i++) {
      for (int j = 0; j < mat[i].size(); j++) {
        if (mat[i][j] == 0) {
          q.push({i, j, 0});
        }
      }
    }
    while (!q.empty()) {
      Thingy cur = q.front();
      q.pop();

      if (cur.i < 0 || cur.i >= mat.size() || cur.j < 0 ||
          cur.j >= mat[0].size()) {
        continue;
      }
      if (cur.distance < mat[cur.i][cur.j] || mat[cur.i][cur.j] < 0 ||
          cur.distance == 0) {
        mat[cur.i][cur.j] = cur.distance;
        q.push({cur.i + 1, cur.j, cur.distance + 1});
        q.push({cur.i - 1, cur.j, cur.distance + 1});
        q.push({cur.i, cur.j + 1, cur.distance + 1});
        q.push({cur.i, cur.j - 1, cur.distance + 1});
      }
    }

    return mat;
  }
  Solution() {}
};

int main() { Solution(); }
