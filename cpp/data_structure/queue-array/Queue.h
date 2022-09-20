#include <iostream>
#include <ostream>

#ifndef QUEUE_H
#define QUEUE_H

template <typename T> class Queue {
  static const int Capacity = 5;

public:
  Queue<T>() : read_(0), write_(0){};
  ~Queue<T>();

  template <typename U>
  friend std::ostream &operator<<(std::ostream &os, Queue<U> &q);

  void enqueue(T value);
  T dequeue();

  bool empty();
  bool full();

private:
  int write_;
  int read_;
  T data_[Capacity + 1];
};

#endif // QUEUE_H
