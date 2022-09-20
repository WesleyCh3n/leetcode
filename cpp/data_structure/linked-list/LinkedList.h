#include <iostream>

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T> struct Node {
  T data;
  Node *next = nullptr;
  Node() {}
  Node(T value) : data(value) {}
};

template <typename T> class LinkedList {
public:
  LinkedList();
  ~LinkedList(){};

  template <typename U>
  friend std::ostream &operator<<(std::ostream &os, LinkedList<U> &l);

  void pushFront(T value);
  T popFront();
  T getFront();

  void pushBack(T value);
  T popBack();
  T getBack();

  void insert(int index, T value);
  void erase(int index);

  T valueNFromEnd(int n);
  void reverse();
  void removeValue(T value);

  int size();
  bool empty();

private:
  Node<T> *head_;
};

#endif // LINKEDLIST_H
