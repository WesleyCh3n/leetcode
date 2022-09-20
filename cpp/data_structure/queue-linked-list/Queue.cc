#include "./Queue.h"

template <typename U> std::ostream &operator<<(std::ostream &os, Queue<U> &q) {
  os << '[';
  Node<U> *ptr = q.head_;
  while (ptr) {
    os << ptr->data;
    if (ptr->next) {
      os << "->";
    }
    ptr = ptr->next;
  }
  os << ']';
  return os;
}

template <typename T> Queue<T>::~Queue() {
  Node<T> *ptr = head_;
  Node<T> *tmp = nullptr;
  while (ptr) {
    tmp = ptr;
    ptr = ptr->next;
    delete tmp;
  }
}

template <typename T> void Queue<T>::enqueue(T value) {
  Node<T> *node = new Node<T>{value};
  node->next = nullptr;
  if (this->empty()) {
    head_ = tail_ = node;
  } else {
    tail_->next = node;
    tail_ = node;
  }
}

template <typename T> T Queue<T>::dequeue() {
  if (this->empty()) {
    std::cout << "[Error] Queue is empty\n";
    exit(EXIT_FAILURE);
  }

  Node<T> *node = head_;
  T result = node->data;
  if (node == tail_) {
    head_ = tail_ = nullptr;
  } else {
    head_ = head_->next;
  }
  delete node;

  return result;
}

template <typename T> bool Queue<T>::empty() { return head_ == nullptr; }
