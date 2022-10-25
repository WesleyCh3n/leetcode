#include "essential.h"
class Solution {
public:
  int kthSmallest(TreeNode *root, int k) {
    //
    int result = 0;
    int cnt = 0;
    inOrder(root, k, result, cnt);
    return result;
  }

  void inOrder(TreeNode *root, int k, int &result, int &cnt) {
    if (root == nullptr) {
      return;
    }

    inOrder(root->left, k, result, cnt);
    cnt++;
    if (cnt == k) {
      result = root->val;
      return;
    }
    inOrder(root->right, k, result, cnt);
  }
};
