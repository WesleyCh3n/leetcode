#include "PriorityQueue.h"
#include <cassert>
#include <math.h>
#include <memory>

std::ostream &operator<<(std::ostream &os, PriorityQueue &q) {
  os << "[\n";
  int f = 1;
  for (int i = 0; i < q.size_; i++) {
    os << q.nodes_[i].key_;
    if (i != q.size_ - 1) {
      os << " ";
    }
    if (i + 1 == std::pow(2, f) - 1) {
      f++;
      os << '\n';
    }
  }
  os << "\n], "
     << "size: " << q.size_ << " cap: " << q.capacity_;
  return os;
}

PriorityQueue::PriorityQueue(int size) {
  this->capacity_ = size;
  nodes_ =
      std::unique_ptr<PriorityQueueNode[]>(new PriorityQueueNode[capacity_]);
}

void PriorityQueue::insert(int key, std::string value) {
  assert(size_ < capacity_);
  // append new node to the last place of the tree
  nodes_[size_].key_ = key;
  nodes_[size_].value_ = value;
  ++size_;

  // siftup the node by index
  siftUp(size_ - 1);
}

void PriorityQueue::siftUp(int index) {
  //
  // am i larger than my parent?
  // yes, let's swap places
  // until i am not larger than my parent
  // also, if i'm the biggest one than no op to do
  //

  int parent = index / 2;
  while (nodes_[index].key_ > nodes_[parent].key_) {
    swapNode(index, parent);
    index = parent;
    if (index == 0)
      break;

    parent = index / 2;
  }
}

void PriorityQueue::swapNode(const int index1, const int index2) {
  std::swap(nodes_[index1].key_, nodes_[index2].key_);
  std::swap(nodes_[index1].value_, nodes_[index2].value_);
}

PriorityQueueNode *PriorityQueue::getMax() { return &nodes_[0]; }

PriorityQueueNode PriorityQueue::extractMax() {
  // todo
  // swap first and last node
  // siftDown the first node because it's the smallest node
  // return last node;
  // remove last node
  int last = size_ - 1;
  swapNode(0, last);
  auto nodes = nodes_[last];
  --size_;
  siftDown(0);
  return nodes;
}

void PriorityQueue::siftDown(int index) {
  //
  // compare two children, who is the biggest one
  // swap with it
  // until you are larger than both of the children
  // also, if there is no more children than no op
  //

  while (2 * index + 1 < size_) { // left child exist
    int compared_child = 2 * index + 1;
    if (2 * index + 2 < size_) { // both children exist
      compared_child = nodes_[2 * index + 1].key_ > nodes_[2 * index + 2].key_
                           ? 2 * index + 1
                           : 2 * index + 2;
    }
    if (nodes_[index].key_ > nodes_[compared_child].key_)
      break;
    swapNode(index, compared_child);
    index = compared_child;
  }
}

int PriorityQueue::getSize() { return size_; }

bool PriorityQueue::isEmpty() { return size_ == 0; }
