#include "Vector.h"
#include <iostream>
#include <vector>

int main() {
  Vector v;
  std::cout << v << '\n';
  v.push(333);
  v.push(222);
  v.push(111);
  std::cout << v << '\n';
  v.pop();
  v.pop();
  v.pop();
  v.is_empty() ? std::cout << "Empty\n" : std::cout << "Not empty\n";
  std::cout << v << '\n';
  v.insert(0, 1);
  std::cout << v << '\n';
  v.prepend(12);
  std::cout << v << '\n';
  std::cout << v.delete_item(0) << '\n';
  std::cout << v << '\n';
  v.push(333);
  v.push(222);
  v.push(111);
  std::cout << v << '\n';
  v.remove(222);
  std::cout << v << '\n';
  std::cout << v.find(2) << '\n';

  return 0;
}
