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
  bool isSubtree(TreeNode *root, TreeNode *subRoot) {
    if (root == nullptr)
      return false;
    if (isSametree(root, subRoot))
      return true;

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
  }

  bool isSametree(TreeNode *p, TreeNode *q) {
    if (p == nullptr && q == nullptr)
      return true;
    if (p == nullptr || q == nullptr) // one of node is not nullptr
      return false;
    return p->val == q->val && isSametree(p->left, q->left) &&
           isSametree(p->right, q->right);
  }
};

int main() {
  std::vector<int> v = {};

  // Solution s;

  return 0;
}
