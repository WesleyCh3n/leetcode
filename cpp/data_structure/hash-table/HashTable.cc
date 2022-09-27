#include "HashTable.h"

template <typename T> HashTable<T>::HashTable() { this->initTable(8); }

template <typename T> HashTable<T>::HashTable(const int size) {
  this->initTable(size);
}

template <typename T> void HashTable<T>::initTable(const int size) {
  this->size_ = size;
  this->data_ = new HashObject<T>[size];

  for (int i = 0; i < size; i++) {
    // NOTE: set all key to null key
    this->data_[i].setNullKey();
  }
}

template <typename T> HashTable<T>::~HashTable() { delete[] this->data_; }

template <typename T> void HashTable<T>::insert(std::string key, T value) {
  // TODO:
  // 1. right on the hash index
  int index = this->hash(key);
  int original_index = index;
  while (this->data_[index].key != HashObject<T>::getNullKey()) {
    // if key exist
    if (this->data_[index].key == key) {
      break;
    } else if (this->data_[index].key == HashObject<T>::getDummyKey()) {
      break;
    }
    index = (index + 1) % this->size_;
    // circle arround
    if (index == original_index) {
      // TODO: out of space
    }
  }
  this->data_[index].key = key;
  this->data_[index].value = value;
}

template <typename T> unsigned int HashTable<T>::hash(const std::string key) {
  unsigned int hash = 0;
  for (int i = 0; i < (int)key.size(); i++) {
    hash += (int)key[i]; // NOTE: charactor to ASCII code
  }
  return hash % this->size_;
}
