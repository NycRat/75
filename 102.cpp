// 102. Binary Tree Level Order Traversal | Dec 28, 2023

#include "TreeNode.h"
#include <queue>
#include <vector>

struct Thingy {
  TreeNode *node;
  int level;
};

class Solution {
public:
  std::vector<std::vector<int>> levelOrder(TreeNode *root) {
    std::vector<std::vector<int>> ans;
    std::queue<Thingy> q;
    q.push({root, 0});

    while (!q.empty()) {
      TreeNode *node = q.front().node;
      int level = q.front().level;
      q.pop();

      if (!node) {
        continue;
      }

      while (level >= ans.size()) {
        ans.push_back({});
      }
      ans[level].push_back(node->val);

      q.push({node->left, level + 1});
      q.push({node->right, level + 1});
    }

    return ans;
  }
  Solution() {}
};

int main() { Solution(); }
