#include <iostream>
#include <stack>
#include <vector>

using namespace std;

template <typename T> void print_vec(vector<T> &v) {
  cout << '[' << ' ';
  for (auto i : v)
    cout << i << ' ';
  cout << ']' << '\n';
}

class Solution {
public:
};

class MinStack {
public:
  stack<int> s;
  stack<int> min_s;
  MinStack() {}

  void push(int val) {
    s.push(val);
    if (min_s.empty() || val <= min_s.top())
      min_s.push(val);
  }

  void pop() {
    if (s.top() == min_s.top())
      min_s.pop();
    s.pop();
  }

  int top() { return s.top(); }

  int getMin() { return min_s.top(); }
};

int main() {
  std::vector<int> v = {};

  Solution s;

  return 0;
}
