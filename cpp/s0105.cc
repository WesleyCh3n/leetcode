#include "essential.h"

class Solution {
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    //
    int index = 0;
    return build(preorder, inorder, index, 0, inorder.size() - 1);
  }
  TreeNode *build(vector<int> &preorder, vector<int> &inorder, int &index,
                  int start, int end) {
    if (start > end) {
      return nullptr;
    }
    auto root = new TreeNode(preorder[index]);
    int split = 0;
    for (int i = start; i < (int)inorder.size(); i++) {
      if (inorder[i] == root->val) {
        // from start to here is left tree
        split = i;
        break;
      }
    }
    index++;
    root->left = build(preorder, inorder, index, start, split - 1);
    root->right = build(preorder, inorder, index, split + 1, end);
    return root;
  }
};

int main() {
  Solution s;
  vector<int> preorder = {3, 9, 20, 15, 7};
  vector<int> inorder = {9, 3, 15, 20, 7};
  s.buildTree(preorder, inorder);
}
