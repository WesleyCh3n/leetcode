#include <iostream>
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
  int climbStairs(int n) {
    int v[n + 1];
    v[0] = 1;
    v[1] = 1;
    for (int i = 2; i <= n; i++) {
      v[i] = v[i - 1] + v[i - 2];
    }
    return v[n];
  }
};

int main() {
  std::vector<int> v = {};

  Solution s;

  return 0;
}
