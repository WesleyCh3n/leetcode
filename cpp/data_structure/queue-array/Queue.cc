#include "./Queue.h"

template <typename U> std::ostream &operator<<(std::ostream &os, Queue<U> &q) {
  // TODO:
  std::cout << q[0];
  return os;
}

template <typename T> Queue<T>::~Queue() {}

template <typename T> void Queue<T>::enqueue(T value) {
  if (this->full()) {
    std::cout << "[Error] Queue is full\n";
    exit(EXIT_FAILURE);
  }
  data_[write_++] = value;
}

template <typename T> T Queue<T>::dequeue() {
  if (this->empty()) {
    std::cout << "[Error] Queue is empty\n";
    exit(EXIT_FAILURE);
  }
  T result = data_[read_];
  data_[read_++] = 0;
  return result;
}

template <typename T> bool Queue<T>::empty() { return read_ == write_; }

template <typename T> bool Queue<T>::full() {
  // read_ + 1 == write_
  // but circular so % length
  return (read_ + 1) % (Capacity + 1) == write_;
}
