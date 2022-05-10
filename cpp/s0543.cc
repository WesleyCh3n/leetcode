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
  int helper(TreeNode *node, int &diameter) {
    if (node == nullptr) {
      return 0;
    }
    int l = helper(node->left, diameter), r = helper(node->right, diameter);
    diameter = max(l + r, diameter); // final answer
    return max(l, r) + 1; // return the highest hand height
  }

  int diameterOfBinaryTree(TreeNode *root) {
    int diameter(0);
    helper(root, diameter);
    return diameter;
  }
};

int main() {
  std::vector<int> v = {};

  Solution s;

  return 0;
}
