#include <iostream>

#ifndef HASHTABLE_H
#define HASHTABLE_H
template <typename T> struct HashObject {
  std::string key;
  T value;
  void setNullKey() { this->key = this->getNullKey(); }
  void setDummyKey() { this->key = this->getDummyKey(); }

  std::string getNullKey() { return ""; }
  std::string getDummyKey() { return "<dummy>"; }
};

template <typename T> class HashTable {
public:
  HashTable();
  HashTable(const int size);
  ~HashTable();

  void insert(std::string key, T value);
  bool exist(std::string key);
  T get(std::string key);
  T remove(std::string key);

private:
  int size_;
  HashObject<T> *data_ = nullptr;
  unsigned int hash(const std::string key);
  void initTable(const int size);
};

#endif
