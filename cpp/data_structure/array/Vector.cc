#include "Vector.h"

Vector::Vector(int capacity) {
  if (capacity < 1) {
    std::cout << "[Error] cannot create with capacity less then 1\n";
    exit(EXIT_FAILURE);
  }
  if (capacity > this->capacity_) {
    this->capacity_ = this->capacity_ * GrowFactor;
  }
  data_ = std::unique_ptr<int[]>(new int[this->capacity_]);
};

Vector::Vector() { data_ = std::unique_ptr<int[]>(new int[this->capacity_]); };

Vector::~Vector(){};

int &Vector::operator[](int index) {
  if (index >= this->size_) {
    std::cout << "[Error] index out of range with size: " << this->size_
              << ", got: " << index << "\n";
    exit(EXIT_FAILURE);
  }
  return data_[index];
}

int &Vector::at(int index) {
  if (index >= this->size_) {
    std::cout << "[Error] index out of range with size: " << this->size_
              << ", got: " << index << "\n";
    exit(EXIT_FAILURE);
  }
  return data_[index];
}

std::ostream &operator<<(std::ostream &os, Vector &v) {
  os << "[";
  for (int i = 0; i < v.size(); i++) {
    os << v[i];
    if (i != v.size() - 1) {
      os << " ";
    }
  }
  os << "], "
     << "size: " << v.size_ << " cap: " << v.capacity_;
  return os;
}

void Vector::resizeSize(int new_size) {
  if (new_size == this->capacity_) {
    // inscrease capacity
    this->capacity_ = this->capacity_ * GrowFactor;
    std::unique_ptr<int[]> new_data(new int[this->capacity_]);
    for (int i = 0; i < this->size_; i++) {
      new_data[i] = this->data_[i];
    }
    this->data_ = std::move(new_data); // TODO: understand this behavior
  } else if (new_size < this->capacity_ / GrowFactor) {
    if (this->capacity_ / GrowFactor > MinCapcity) {
      this->capacity_ = this->capacity_ / GrowFactor;
      std::unique_ptr<int[]> new_data(new int[this->capacity_]);
      for (int i = 0; i < this->size_; i++) {
        new_data[i] = this->data_[i];
      }
      this->data_ = std::move(new_data);
    }
  }
}

int Vector::size() { return this->size_; }

bool Vector::is_empty() { return this->size_ == 0; }

void Vector::push(int value) {
  resizeSize(this->size_ + 1);
  this->data_[size_] = value;
  ++this->size_;
}

int Vector::pop() {
  if (this->size_ == 0) {
    std::cout << "[Error] There is nothing to pop!\n";
    exit(EXIT_FAILURE);
  }
  resizeSize(size_ - 1);
  int value = this->data_[this->size_ - 1]; // don't care what its inside then
  --this->size_;
  return value;
}

void Vector::insert(int index, int value) {
  if (index < 0 || index > this->size_) {
    std::cout << "[Error] index out of valid range\n";
    exit(EXIT_FAILURE);
  }
  resizeSize(this->size_ + 1);
  for (int i = this->size_; i > index; i--) {
    this->data_[this->size_] = this->data_[this->size_ - 1];
  }
  this->data_[index] = value;
  ++this->size_;
}

void Vector::prepend(int value) { this->insert(0, value); }

int Vector::delete_item(int index) {
  if (index < 0 || index >= this->size_) {
    std::cout << "[Error] index out of valid range\n";
    exit(EXIT_FAILURE);
  }
  resizeSize(--this->size_);
  int value = this->data_[index];
  for (int i = index; i < this->size_; i++) {
    this->data_[i] = this->data_[i + 1];
  }
  return value;
}

void Vector::remove(int value) {
  for (int i = 0; i < this->size_; i++) {
    if (this->data_[i] == value) {
      this->delete_item(i);
      i--;
    }
  }
}

int Vector::find(int value) {
  for (int i = 0; i < this->size_; i++) {
    if (this->data_[i] == value)
      return i;
  }
  return -1;
}
