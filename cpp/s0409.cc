#include <iostream>
#include <unordered_map>
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
  int longestPalindrome(string s) {
    unordered_map<char, int> map;
    for (auto c : s) {
      map[c]++;
    }
    int oddGroup = 0;
    for (auto v : map) {
      oddGroup += v.second & 1;
      /* if (v.second % 2 == 1) {
        oddGroup += 1;
      } */
    }
    return s.size() - oddGroup + (oddGroup > 0);
  }
};

int main() {
  std::vector<int> v = {};

  Solution s;

  return 0;
}
