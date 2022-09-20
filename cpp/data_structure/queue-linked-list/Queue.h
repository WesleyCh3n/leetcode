#include <iostream>
#include <ostream>

#ifndef QUEUE_H
#define QUEUE_H

template <typename T> struct Node {
  T data;
  Node *next;
  Node(T value) : data(value), next(nullptr) {}
};

template <typename T> class Queue {
public:
  Queue<T>(){};
  ~Queue<T>();

  template <typename U>
  friend std::ostream &operator<<(std::ostream &os, Queue<U> &q);

  void enqueue(T value);
  T dequeue();

  bool empty();

private:
  Node<T> *head_ = nullptr;
  Node<T> *tail_ = nullptr;
};

#endif // QUEUE_H
