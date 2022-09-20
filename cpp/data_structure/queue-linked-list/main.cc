#include "./Queue.cc"
#include "./Queue.h"
#include <iostream>

int main() {
  Queue<int> queue;
  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);
  queue.enqueue(4);
  std::cout << queue << '\n';
  std::cout << queue.dequeue() << '\n';
  std::cout << queue << '\n';
  std::cout << queue.dequeue() << '\n';
  std::cout << queue << '\n';
  std::cout << queue.dequeue() << '\n';
  std::cout << queue << '\n';
  std::cout << queue.dequeue() << '\n';
  std::cout << queue << '\n';
  std::cout << queue.dequeue() << '\n';
  std::cout << queue << '\n';
  return 0;
}
