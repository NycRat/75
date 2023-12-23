// 104. Maximum Depth of Binary Tree | Nov 22, 2023

#include "TreeNode.h"
#include <iostream>

class Solution {
public:
  int maxDepth(TreeNode *root) {
    if (!root) {
      return 0;
    }
    return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
  }
  Solution() {}
};

int main() { Solution(); }
