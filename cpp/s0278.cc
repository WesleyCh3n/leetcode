#include <iostream>
#include <vector>

using namespace std;

template <typename T> void print_vec(vector<T> &v) {
  cout << '[' << ' ';
  for (auto i : v)
    cout << i << ' ';
  cout << ']' << '\n';
}

bool isBadVersion(int version);

class Solution {
public:
  int firstBadVersion(int n) {
    int start = 0, end = n;

    while(start + 1 < end) {
      int mid = start + (end - start) /2;
      if (isBadVersion(mid))
        end = mid;
      else
        start = mid;
    }
    return end;
  }
};

int main() {
  std::vector<int> v = {};

  Solution s;

  return 0;
}
