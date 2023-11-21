// 110. Balanced Binary Tree | Nov 20, 2023

#include "TreeNode.h"
#include <algorithm>
#include <iostream>

class Solution {
public:
  int setDepths(TreeNode *root) {
    if (!root) {
      return 0;
    }
    root->val = std::max(setDepths(root->left), setDepths(root->right)) + 1;
    return root->val;
  }
  bool isBalancedNoSet(TreeNode *root) {
    if (!root) {
      return true;
    }
    if (!root->right && !root->left) {
      return true;
    }
    if (!root->right) {
      if (root->left->val >= 2) {
        return false;
      }
    } else if (!root->left) {
      if (root->right->val >= 2) {
        return false;
      }
    } else if (std::abs(root->left->val - root->right->val) >= 2) {
      return false;
    }
    return isBalancedNoSet(root->left) && isBalancedNoSet(root->right);
  }
  bool isBalanced(TreeNode *root) {
    if (!root) {
      return true;
    }
    root->val = setDepths(root);
    return isBalancedNoSet(root);
  }
  Solution() {}
};

int main() { Solution(); }
