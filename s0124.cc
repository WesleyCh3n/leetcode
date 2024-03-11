/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  int maxPathSum(TreeNode* root) {
    int result = INT_MIN;
    dfs(root, result);
    return result;
  }
  int dfs(TreeNode* root, int &max_path) {
    if (root == nullptr) {
      return 0;
    }
    int left_sum = max(dfs(root->left, max_path), 0);
    int right_sum = max(dfs(root->right, max_path), 0);
    max_path = max(left_sum + right_sum + root->val, max_path);
    return root->val + max(left_sum, right_sum);
  }
};
