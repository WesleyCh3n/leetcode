#include "./Queue.h"

template <typename U> std::ostream &operator<<(std::ostream &os, Queue<U> &q) {
  // TODO:
  os << '[';
  int i = q.read_;
  if (!q.empty()) {
    do {
      os << q.data_[i];
      i = ++i % (q.Capacity + 1);
      if (i != q.write_) {
        os << ' ';
      }
    } while (i != q.write_);
  }
  os << ']';
  return os;
}

template <typename T> Queue<T>::~Queue() {}

template <typename T> void Queue<T>::enqueue(T value) {
  if (this->full()) {
    std::cout << "[Error] Queue is full\n";
    exit(EXIT_FAILURE);
  }
  data_[write_++] = value;

  if ((write_ % (Capacity + 1)) == 0) {
    write_ = 0;
  }
}

template <typename T> T Queue<T>::dequeue() {
  if (this->empty()) {
    std::cout << "[Error] Queue is empty\n";
    exit(EXIT_FAILURE);
  }
  T result = data_[read_];
  data_[read_++] = 0;
  if ((read_ % (Capacity + 1)) == 0) {
    read_ = 0;
  }
  return result;
}

template <typename T> bool Queue<T>::empty() { return read_ == write_; }

template <typename T> bool Queue<T>::full() {
  // write_ + 1 == read_
  // but circular so % length
  return (write_ + 1) % (Capacity + 1) == read_;
}
