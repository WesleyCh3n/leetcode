#include "LinkedList.cc"
#include "LinkedList.h"

#include <iostream>

int main() {
  LinkedList<int> list;
  list.pushBack(4);
  std::cout << list << '\n';
  std::cout << "size: " << list.size() << '\n';
  std::cout << "empty: " << list.empty() << '\n';
  list.pushFront(1);
  list.pushFront(2);
  list.pushFront(3);
  std::cout << list << '\n';
  std::cout << "size: " << list.size() << '\n';
  std::cout << list.popFront() << '\n';
  std::cout << list << '\n';
  list.pushBack(4);
  std::cout << list << '\n';
  std::cout << "getFront: " << list.getFront() << '\n';
  std::cout << "getBack: " << list.getBack() << '\n';
  std::cout << "popBack: " << list.popBack() << '\n';
  std::cout << list << '\n';
  std::cout << "size: " << list.size() << '\n';
  std::cout << "empty: " << list.empty() << '\n';
  list.insert(2, 12);
  std::cout << list << '\n';
  list.insert(0, 11);
  std::cout << list << '\n';
  list.insert(4, 100);
  std::cout << list << '\n';
  list.insert(list.size(), 101);
  std::cout << list << '\n';
  std::cout << list.size() << '\n';
  list.erase(list.size() - 1);
  std::cout << list << '\n';
  std::cout << list.valueNFromEnd(2) << '\n';
  list.reverse();
  std::cout << list << '\n';
  list.pushBack(12);
  std::cout << list << '\n';
  list.removeValue(12);
  std::cout << list << '\n';

  return 0;
}
