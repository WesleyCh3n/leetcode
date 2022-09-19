#include <iostream>
#include <memory>

static const int GrowFactor = 2;
static const int MinCapcity = 16;

class Vector {
public:
  Vector();
  Vector(int capacity);
  Vector(Vector &v1); // NOTE: copy constructor
  ~Vector();

  int &operator[](int index);
  int &at(int index);
  friend std::ostream &operator<<(std::ostream &os, Vector &v);
  Vector operator+(const Vector &other);
  Vector &operator=(const Vector &other);

  int size();
  bool is_empty();
  void push(int value);
  int pop();
  void insert(int index, int value);
  void prepend(int value);
  int delete_item(int index);

  void remove(int value);
  int find(int value);

private:
  std::unique_ptr<int[]> data_;
  int capacity_{MinCapcity};
  int size_{0};

  void resizeSize(int new_size);
};
