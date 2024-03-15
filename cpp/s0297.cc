/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    string result = "";
    dfs(root, result);
    return result.substr(0, result.size() - 1); // remove trailing ,
  }

  void dfs(TreeNode *root, string &result) {
    if (root == nullptr) {
      result += "N,";
      return;
    }
    result += to_string(root->val) + ",";
    dfs(root->left, result);
    dfs(root->right, result);
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    vector<string> v;
    stringstream ss(data);
    string str;
    while(getline(ss, str, ',')) {
      v.emplace_back(str);
    }
    int i = 0;
    return dedfs(v, i);
  }
  TreeNode* dedfs(vector<string> &v, int &i) {
    if (v[i] == "N") {
      i += 1
      return nullptr;
    }
    TreeNode *node = new TreeNode(stoi(v[i]));
    i += 1;
    node->left = dedfs(v, i);
    node->right = dedfs(v, i);
    return node;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
