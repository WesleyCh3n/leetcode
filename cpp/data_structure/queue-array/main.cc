#include "./Queue.cc"
#include "./Queue.h"
#include <iostream>

int main() {
  Queue<int> queue;
  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);
  queue.enqueue(4);
  return 0;
}
