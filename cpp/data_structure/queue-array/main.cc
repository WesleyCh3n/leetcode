#include "./Queue.cc"
#include "./Queue.h"
#include <iostream>

int main() {
  Queue<int> queue;
  std::cout << queue << '\n';
  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);
  queue.enqueue(4);
  queue.enqueue(5);
  std::cout << queue << '\n';

  queue.dequeue();
  std::cout << queue << '\n';
  queue.enqueue(6);
  std::cout << queue << '\n';
  queue.dequeue();
  queue.enqueue(7);
  std::cout << queue << '\n';
  queue.dequeue();
  queue.enqueue(8);
  std::cout << queue << '\n';
  queue.dequeue();
  queue.enqueue(9);
  std::cout << queue << '\n';
  queue.dequeue();
  queue.dequeue();
  queue.dequeue();
  queue.dequeue();
  queue.enqueue(10);
  std::cout << queue << '\n';

  return 0;
};
