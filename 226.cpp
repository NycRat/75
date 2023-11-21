// 226. Invert Binary Tree | Nov 20, 2023

#include "TreeNode.h"
#include <iostream>

class Solution {
public:
  TreeNode *invertTree(TreeNode *root) {
    if (!root) {
      return nullptr;
    }
    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
  }
  Solution() {}
};

int main() { Solution(); }
