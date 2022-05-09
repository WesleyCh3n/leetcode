#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

template <typename T> void print_vec(vector<T> &v) {
  cout << '[' << ' ';
  for (auto i : v)
    cout << i << ' ';
  cout << ']' << '\n';
}

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  /* buttom up sol */
  int depth(TreeNode *root) {
    if (root == nullptr)
      return 0;
    return max(depth(root->left), depth(root->right)) + 1;
  }
  bool isBalanced(TreeNode *root) {
    if (root == nullptr)
      return true;
    return abs(depth(root->left) - depth(root->right)) <= 1 &&
           isBalanced(root->left) && isBalanced(root->right);
  }

  /* optimization */
  bool isBalanced_opt(TreeNode *root) {
    // return tree depth
    return depth_dfs(root) != -1;
  }
  int depth_dfs(TreeNode *root) {
    if (root == nullptr)
      return 0;

    int l = depth_dfs(root->left);
    int r = depth_dfs(root->right);
    if (abs(l - r) > 1 || l == -1 || r == -1) {
      return -1;
    }

    return max(l, r) + 1;
  }
};

int main() {
  std::vector<int> v = {};

  Solution s;

  return 0;
}
