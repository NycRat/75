// 543. Diameter of Binary Tree | Nov 21, 2023

#include "TreeNode.h"
#include <algorithm>
#include <iostream>

class Solution {
public:
  int ans = 0;
  int getDepth(TreeNode *node) {
    if (!node) {
      return 0;
    }
    node->val = std::max(getDepth(node->left), getDepth(node->right)) + 1;
    return node->val;
  }
  int getVal(TreeNode* node) {
    return node ? node->val : 0;
  }
  void dfs(TreeNode *node) {
    if (!node) {
      return;
    }
    ans = std::max(ans, getVal(node->left) + getVal(node->right));
    dfs(node->left);
    dfs(node->right);
  }
  int diameterOfBinaryTree(TreeNode *root) {
    getDepth(root);
    dfs(root);
    return ans;
  }
  Solution() {}
};

int main() { Solution(); }
