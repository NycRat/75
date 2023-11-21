// 235. Lowest Common Ancestor of a Binary Search Tree | Nov 20, 2023

#include "TreeNode.h"
#include <algorithm>
#include <iostream>
#include <unordered_set>

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    int low = std::min(p->val, q->val);
    int high = std::max(p->val, q->val);
    while (root) {
      // if increase (go right), low should be greater than root
      // if decrease (go left), high should be lesser than root
      int val = root->val;
      if (low > val && high > val) {
        root = root->right;
      } else if (low < val && high < val) {
        root = root->left;
      } else {
        break;
      }
    }
    return root;
    /*
     *    2
     *   1
     *
     *
     *
     *         0
     *      -2   2
     *    -5 -1 1  5
     */
    // while (root->left && root->val > std::max(p->val, q->val)) {
    //   root = root->left;
    // }
    // return root;
    // while (p && q) {
    //   if (p->val == q->val) {
    //     break;
    //   }
    //   if (p->val > q->val) {
    //     q = q->right;
    //   } else {
    //     p = p->right;
    //   }
    // }
    // while (p->left) {
    //   p = p->left;
    // }
    // return p;
  }
  Solution() {}
};

int main() { Solution(); }
