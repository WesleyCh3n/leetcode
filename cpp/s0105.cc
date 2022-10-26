#include "essential.h"
#include <unordered_map>

class Solution {
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    //
    int index = 0;
    std::unordered_map<int, int> m;
    for (int i = 0; i < (int)inorder.size(); i++) {
      m[inorder[i]] = i;
    }
    // return build(preorder, inorder, index, 0, inorder.size() - 1);
    return build(preorder, m, index, 0, inorder.size() - 1);
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
  TreeNode *build(vector<int> &preorder, std::unordered_map<int, int> &m,
                  int &preIndex, int inStart, int inEnd) {
    if (inStart > inEnd) {
      return nullptr;
    }
    int pVal = preorder[preIndex];
    int inIndex = m[pVal];
    auto node = new TreeNode(pVal);
    preIndex++;
    node->left = build(preorder, m, preIndex, inStart, inIndex - 1);
    node->right = build(preorder, m, preIndex, inIndex + 1, inEnd);
    return node;
  }
};

int main() {
  Solution s;
  vector<int> preorder = {3, 9, 20, 15, 7};
  vector<int> inorder = {9, 3, 15, 20, 7};
  s.buildTree(preorder, inorder);
}
