#include "../LinkedList.cc"
#include "../LinkedList.h"
#include <cassert>

int main() {
  LinkedList<int> list;
  list.pushBack(1);
  list.reverse();
  assert(list.getFront() == 1);

  list.pushBack(2);
  list.reverse();
  assert(list.getFront() == 2);

  list.pushBack(3);
  list.pushBack(4);
  list.pushBack(5);
  list.pushBack(6);
  list.reverse();

  // std::cout << list << '\n';
  assert(list.getFront() == 6);
  assert(list.getBack() == 2);
  return 0;
}
