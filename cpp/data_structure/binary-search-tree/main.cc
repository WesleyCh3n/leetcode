#include "BinarySearchTreeSimple.h"
#include <iostream>

int main() {
  // todo
  BSTNode *node = getNewNode(7);

  node = insert(node, 2);
  node = insert(node, 3);
  node = insert(node, 10);
  node = insert(node, 5);
  node = insert(node, 12);
  node = insert(node, 8);
  printDFS(node);
  std::cout << std::endl;
  printBFS(node);
  std::cout << std::endl;
  printDFSPretty(node, 0);
  std::cout << "node cnt: " << getNodeCount(node) << '\n';

  std::cout << "3 is in tree: " << isInTree(node, 3) << '\n';
  std::cout << "4 is in tree: " << isInTree(node, 4) << '\n';
  std::cout << "10 is in tree: " << isInTree(node, 10) << '\n';
  std::cout << "100 is in tree: " << isInTree(node, 100) << '\n';
  std::cout << "101 is in tree: " << isInTree(node, 101) << '\n';

  std::cout << "get height: " << getHeight(node) << '\n';

  std::cout << "getMin: " << getMin(node) << '\n';
  std::cout << "getMax: " << getMax(node) << '\n';

  std::cout << "node is bst: " << isBST(node) << '\n';

  {
    BSTNode *not_a_bst = getNewNode(4);
    not_a_bst->left = node;
    not_a_bst->right = getNewNode(1);
    not_a_bst->right->right = getNewNode(2);
    not_a_bst->right->left = getNewNode(8);
    std::cout << "not_a_bst is bst: " << isBST(not_a_bst) << '\n';
  }

  node = deleteValue(node, 10);
  printDFSPretty(node, 0);
  std::cout << std::endl;

  return 0;
}
