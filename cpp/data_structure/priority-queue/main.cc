#include "PriorityQueue.h"

int main() {
  PriorityQueue q(16);
  std::cout << "is empty: " << q.isEmpty() << '\n';
  q.insert(12, "");
  q.insert(9, "");
  std::cout << q << '\n';
  q.insert(13, "");
  q.insert(1, "");
  q.insert(2, "");
  q.insert(10, "");
  std::cout << q << '\n';
  q.insert(22, "");
  std::cout << q.getMax()->key_ << '\n';
  std::cout << "is empty: " << q.isEmpty() << '\n';
  std::cout << "extract max: " << q.extractMax().key_ << '\n';
  std::cout << q << '\n';
  std::cout << "extract max: " << q.extractMax().key_ << '\n';
  std::cout << q << '\n';
  std::cout << "extract max: " << q.extractMax().key_ << '\n';
  std::cout << q << '\n';
  return 0;
}
