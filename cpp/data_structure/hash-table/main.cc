#include "HashTable.cc"
#include "HashTable.h"

#include <iostream>

int main() {
  // todo
  HashTable<int> table(8);
  table.insert("a_key", 12);
  table.insert("b_key", 14);
  return 0;
}
