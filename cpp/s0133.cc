#include "essential.h"
#include <unordered_set>

// Definition for a Node.
class Node {
public:
  int val;
  vector<Node *> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node *>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node *>();
  }
  Node(int _val, vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
public:
  std::unordered_set<int> visted;
  std::unordered_map<Node *, Node *> clonedMap;
  Node *cloneGraph(Node *node) {
    dfs(node);
    return clonedMap[node];
  }
  void dfs(Node *node) {
    if (node == nullptr) {
      return;
    }

    if (clonedMap.find(node) != clonedMap.end()) {
      return;
    }

    clonedMap[node] = new Node(node->val);

    for (int i = 0; i < (int)node->neighbors.size(); i++) {
      dfs(node->neighbors[i]);
      clonedMap[node]->neighbors.push_back(clonedMap[node->neighbors[i]]);
    }
  }
};
