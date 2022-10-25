#include "essential.h"
class Solution {
public:
  bool isValidBST(TreeNode *root) {
    // return isBetween(root, INT_MIN, INT_MAX);
    TreeNode *prev = nullptr;
    return inOrder(root, prev);
  }
  /* if there is no INT_MIN & INT_MAX */
  bool isBetween(TreeNode *root, int minVal, int maxVal) {
    if (root == nullptr) {
      return true;
    }
    return root->val > minVal && root->val < maxVal &&
           isBetween(root->left, minVal, root->val) &&
           isBetween(root->right, root->val, maxVal);
  }

  bool inOrder(TreeNode *root, TreeNode *&prev) {
    if (root == nullptr)
      return true;
    if (!inOrder(root->left, prev))
      return false;
    if (prev != nullptr && root->val <= prev->val) {
      return false;
    }
    prev = root;
    if (!inOrder(root->right, prev))
      return false;
    return true;
  }
};
