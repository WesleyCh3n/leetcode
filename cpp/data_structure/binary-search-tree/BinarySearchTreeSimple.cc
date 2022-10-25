#include "BinarySearchTreeSimple.h"
#include <climits>

void printDFS(BSTNode *node) {
  if (node != nullptr) {
    printDFS(node->left);
    std::cout << node->data << ' ';
    printDFS(node->right);
  }
}

void printDFSPretty(BSTNode *node, int level) {
  if (node != nullptr) {
    printDFSPretty(node->left, level + 1);
    std::cout << std::string(4 * level, ' ') << "->" << node->data << '\n';
    printDFSPretty(node->right, level + 1);
  }
}

void printBFS(BSTNode *node) {
  std::queue<BSTNode *> q;
  q.push(node);
  while (!q.empty()) {
    BSTNode *curr = q.front();
    q.pop();
    if (curr->left != nullptr) {
      q.push(curr->left);
    }
    if (curr->right != nullptr) {
      q.push(curr->right);
    }
    std::cout << curr->data << ' ';
  }
}

BSTNode *getNewNode(int value) {
  BSTNode *node = new BSTNode;
  node->data = value;
  node->left = nullptr;
  node->right = nullptr;
  return node;
}

BSTNode *insert(BSTNode *node, int value) {
  if (node == nullptr) {
    return getNewNode(value);
  }

  if (value < node->data) {
    node->left = insert(node->left, value);
  } else {
    node->right = insert(node->right, value);
  }
  return node;
}

int getNodeCount(BSTNode *node) {
  if (node == nullptr) {
    return 0;
  }
  return 1 + getNodeCount(node->left) + getNodeCount(node->right);
}

void deleteTree(BSTNode *node) {
  if (node == nullptr) {
    return;
  }
  deleteTree(node->left);
  deleteTree(node->right);

  delete node;
}

bool isInTree(BSTNode *node, int value) {
  if (node == nullptr) {
    return false;
  }

  if (value < node->data) {
    return isInTree(node->left, value);
  } else if (value > node->data) {
    return isInTree(node->right, value);
  }
  return true;
}

int getHeight(BSTNode *node) {
  if (node == nullptr) {
    return 0;
  }

  return 1 + std::max(getHeight(node->left), getHeight(node->right));
}

int getMin(BSTNode *node) {
  if (node->left == nullptr) {
    return node->data;
  }
  return getMin(node->left);
}

BSTNode *getMinNode(BSTNode *node) {
  if (node->left == nullptr) {
    return node;
  }
  return getMinNode(node->left);
}

int getMax(BSTNode *node) {
  if (node->right == nullptr) {
    return node->data;
  }
  return getMax(node->right);
}

BSTNode *getMaxNode(BSTNode *node) {
  if (node->right == nullptr) {
    return node;
  }
  return getMaxNode(node->right);
}

bool isBST(BSTNode *node) { return isBetween(node, INT_MIN, INT_MAX); }

bool isBetween(BSTNode *root, int minVal, int maxVal) {
  if (root == nullptr) {
    return true;
  }
  std::cout << root->data << " " << minVal << " " << maxVal << '\n'
            << "data > minval: " << (root->data > minVal) << '\n'
            << "data < maxVal: " << (root->data > maxVal) << '\n';
  if (root->data == INT_MIN) {
    return root->left == nullptr && isBetween(root->right, INT_MIN + 1, maxVal);
  }
  if (root->data == INT_MAX) {
    return root->right == nullptr && isBetween(root->left, minVal, INT_MAX - 1);
  }

  return root->data > minVal && root->data < maxVal &&
         isBetween(root->left, minVal, root->data) &&
         isBetween(root->right, root->data, maxVal);
}

BSTNode *deleteValue(BSTNode *node, int value) {
  if (node == nullptr) {
    return nullptr;
  }

  if (value < node->data) {
    node->left = deleteValue(node->left, value);
  } else if (value > node->data) {
    node->right = deleteValue(node->right, value);
  } else { // this is the one
    // node is leaf
    if (node->left == nullptr && node->right == nullptr) {
      delete node;
      node = nullptr;
    } else if (node->left == nullptr) { // node has right children
      BSTNode *tmp = node;
      node = node->right;
      delete tmp;
    } else if (node->right == nullptr) { // node has left children
      BSTNode *tmp = node;
      node = node->left;
      delete tmp;
    } else { // node has two children
      // move right min to top
      int min_val = getMin(node->right);
      node->data = min_val;
      node->right = deleteValue(node->right, min_val);
    }
  }

  return node;
}

BSTNode *getSuccessor(BSTNode *node, int value) {
  if (node == nullptr)
    return node;
  BSTNode *target = node;
  while (node->data != value) {
    if (value < node->data) {
      target = node->left;
    } else if (value > node->data) {
      target = node->right;
    }
  }

  if (target->right != nullptr) {
    return getMinNode(target->right);
  }

  // find deepest ancestor where value is in left subtree
  BSTNode *successor = nullptr;
  BSTNode *ancestor = node;
  while (ancestor != nullptr) {
    if (value < ancestor->data) {
      successor = ancestor;
      ancestor = ancestor->left;
    } else {
      ancestor = ancestor->right;
    }
  }

  return successor;
  return nullptr;
}
