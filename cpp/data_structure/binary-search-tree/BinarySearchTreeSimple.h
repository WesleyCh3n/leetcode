#include <iostream>
#include <queue>

#ifndef BST_H
#define BST_H

struct BSTNode {
  int data;
  BSTNode *left;
  BSTNode *right;
};

void printDFS(BSTNode *node);
void printDFSPretty(BSTNode *node, int level);

void printBFS(BSTNode *node);

BSTNode *getNewNode(int value);
BSTNode *insert(BSTNode *node, int value);

BSTNode *deleteValue(BSTNode *node, int value);

int getNodeCount(BSTNode *node);
void deleteTree(BSTNode *node);
bool isInTree(BSTNode *node, int value);
int getHeight(BSTNode *node);

int getMin(BSTNode *node);
BSTNode *getMinNode(BSTNode *node);
int getMax(BSTNode *node);
BSTNode *getMaxNode(BSTNode *node);

bool isBST(BSTNode *node);
bool isBetween(BSTNode *root, int minVal, int maxVal);

BSTNode *getSuccessor(BSTNode *node, int value);

#endif
