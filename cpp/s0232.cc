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

class MyQueue {
public:
  stack<int> input, output;
  MyQueue() {}

  void push(int x) { input.push(x); }

  int pop() {
    while (output.empty()) {
      while (!input.empty()) {
        output.push(input.top());
        input.pop();
      }
    }
    int val = output.top();
    output.pop();
    return val;
  }

  int peek() {
    while (output.empty()) {
      while (!input.empty()) {
        output.push(input.top());
        input.pop();
      }
    }
    return output.top();
  }

  bool empty() { return input.empty() && output.empty(); }
};

int main() {
  std::vector<int> v = {};

  Solution s;

  return 0;
}
