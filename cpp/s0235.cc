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
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (p->val < root->val && q->val < root->val)
      return lowestCommonAncestor(root->left, p, q);
    else if (p->val > root->val && q->val > root->val)
      return lowestCommonAncestor(root->right, p, q);
    else
      return root;
  }
  TreeNode *lowestCommonAncestor_iter(TreeNode *root, TreeNode *p, TreeNode *q) {
    while (true) {
      if (p->val < root->val && q->val < root->val)
        root = root->left;
      else if (p->val > root->val && q->val > root->val)
        root = root->right;
      else
        return root;
    }
  }
};

int main() {
  std::vector<int> v = {};

  Solution s;

  return 0;
}
