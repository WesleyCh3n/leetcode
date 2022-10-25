#include "essential.h"
#include <queue>

class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> result;
    if (root == nullptr) {
      return {};
    }
    std::queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      int size = q.size();
      vector<int> curr_level;
      for (int i = 0; i < size; i++) {
        auto node = q.front();
        q.pop();
        if (node->left != nullptr) {
          q.push(node->left);
        }
        if (node->right != nullptr) {
          q.push(node->right);
        }
        curr_level.push_back(node->val);
      }
      result.push_back(curr_level);
    }
    return result;
  }
};

int main() { return 0; }
