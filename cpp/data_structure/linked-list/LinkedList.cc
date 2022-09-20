#include "LinkedList.h"

template <typename T>
std::ostream &operator<<(std::ostream &os, LinkedList<T> &l) {
  Node<T> *ptr = l.head_;
  os << '[';
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

template <typename T> LinkedList<T>::LinkedList() : head_(nullptr) {}
template <typename T> LinkedList<T>::~LinkedList() {
  Node<T> *ptr = head_;
  Node<T> *tmp = nullptr;
  while (ptr) {
    tmp = ptr;
    ptr = ptr->next;
    delete tmp;
  }
}

template <typename T> void LinkedList<T>::pushFront(T value) {
  Node<T> *node = new Node<T>(value);
  node->next = head_;
  head_ = node;
}

template <typename T> T LinkedList<T>::popFront() {
  if (!head_) {
    std::cout << "[Error] List is empty\n";
    exit(EXIT_FAILURE);
  }
  Node<T> *node = head_;
  T result = node->data;
  head_ = node->next;
  delete node;

  return result;
}

template <typename T> void LinkedList<T>::pushBack(T value) {
  Node<T> *node = new Node<T>(value);
  if (!head_) {
    head_ = node;
    return;
  }

  Node<T> *ptr = head_;
  while (ptr) {
    if (!ptr->next) {
      ptr->next = node;
      break;
    }
    ptr = ptr->next;
  }
}

template <typename T> T LinkedList<T>::popBack() {
  if (!head_) {
    std::cout << "[Error] List is empty\n";
    exit(EXIT_FAILURE);
  }
  Node<T> *ptr = head_;
  T result;
  while (ptr->next) {
    if (!ptr->next->next) {
      result = ptr->next->data;
      ptr->next = nullptr;
      return result;
    }
    ptr = ptr->next;
  }
  // there is only one node
  result = ptr->data;
  head_ = nullptr;
  return result;
}

template <typename T> T LinkedList<T>::getFront() {
  if (!head_) {
    std::cout << "[Error] List is empty\n";
    exit(EXIT_FAILURE);
  }
  return head_->data;
}

template <typename T> T LinkedList<T>::getBack() {
  if (!head_) {
    std::cout << "[Error] List is empty\n";
    exit(EXIT_FAILURE);
  }
  Node<T> *ptr = head_;
  while (ptr) {
    if (!ptr->next) {
      return ptr->data;
    }
    ptr = ptr->next;
  }
  // FIX: reach non-void function
}

template <typename T> void LinkedList<T>::insert(int index, T value) {
  Node<T> *ptr = head_;
  Node<T> *prev = nullptr;
  int i;
  for (i = 0; i < index && ptr; i++) {
    prev = ptr;
    ptr = ptr->next;
  }
  if (i != index) {
    std::cout << "[Error] index out of bound\n";
    exit(EXIT_FAILURE);
  }

  Node<T> *node = new Node<T>{value};
  if (!prev) {
    node->next = head_;
    head_ = node;
  } else {
    node->next = ptr;
    prev->next = node;
  }
}

template <typename T> void LinkedList<T>::erase(int index) {
  if (!head_) {
    std::cout << "[Error] List is empty\n";
    exit(EXIT_FAILURE);
  }

  Node<T> *ptr = head_;
  Node<T> *prev = nullptr;
  int i;
  for (i = 0; i < index && ptr; ++i) {
    prev = ptr;
    ptr = ptr->next;
  }
  if (i != index || ptr == nullptr) { // NOTE: if current ptr is the end
    std::cout << "[Error] index out of bound\n";
    exit(EXIT_FAILURE);
  }

  if (!prev) {
    head_ = ptr->next;
  } else {
    prev->next = ptr->next;
  }
}

template <typename T> T LinkedList<T>::valueNFromEnd(int n) {
  if (!head_) {
    std::cout << "[Error] List is empty\n";
    exit(EXIT_FAILURE);
  }
  Node<T> *ptr = head_;
  int i;
  for (i = 0; i < n && ptr; i++) {
    ptr = ptr->next;
  }

  if (i != n) {
    std::cout << "[Error] index out of bound\n";
    exit(EXIT_FAILURE);
  }

  std::cout << ptr->data << '\n';
  Node<T> *result = head_;
  while (ptr) {
    result = result->next;
    ptr = ptr->next;
  }
  return result->data;
}

template <typename T> void LinkedList<T>::reverse() {
  Node<T> *ptr = head_;
  Node<T> *next = nullptr, *prev = nullptr;
  while (ptr) {
    next = ptr->next;
    ptr->next = prev;
    prev = ptr;
    ptr = next;
  }
  head_ = prev;
}

template <typename T> void LinkedList<T>::removeValue(T value) {
  Node<T> *ptr = head_;
  Node<T> *prev = nullptr;
  while (ptr) {
    if (ptr->data == value) {
      // remove this node
      if (prev == nullptr) {
        head_ = ptr->next;
      } else {
        prev->next = ptr->next;
      }
      return;
    }
    prev = ptr;
    ptr = ptr->next;
  }
}

template <typename T> int LinkedList<T>::size() {
  int num = 0;
  Node<T> *ptr = head_;
  while (ptr) {
    num += 1;
    ptr = ptr->next;
  }
  return num;
}

template <typename T> bool LinkedList<T>::empty() { return head_ == nullptr; }
