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
  int maxDepth(TreeNode *root) {
    return root ? max(maxDepth(root->left), maxDepth(root->right)) + 1 : 0;
  }
  int maxDepth_II(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
  }
};

int main() {
  std::vector<int> v = {};

  Solution s;

  return 0;
}
