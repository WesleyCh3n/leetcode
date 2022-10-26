#include <iostream>
#include <memory>

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

typedef struct PriorityQueueNode {
  int key_;
  std::string value_;
} PriorityQueueNode;

class PriorityQueue {
public:
  PriorityQueue(int size);
  friend std::ostream &operator<<(std::ostream &os, PriorityQueue &q);
  void insert(int key, std::string value);
  PriorityQueueNode *getMax();
  PriorityQueueNode extractMax();
  int getSize();
  bool isEmpty();

private:
  int size_ = 0;
  int capacity_ = 0;
  std::unique_ptr<PriorityQueueNode[]> nodes_;

  void siftUp(int index);
  void siftDown(int index);
  void swapNode(const int index1, const int index2);
};

#endif
