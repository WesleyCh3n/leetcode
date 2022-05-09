#include <algorithm>
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
  bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> map;
    for (auto c: magazine) {
      map[c] ++;
    }

    for (auto c: ransomNote) {
      if (map[c] > 0)
        map[c] --;
      else
        return false;
    }
    return true;
  }
};

int main() {
  std::vector<int> v = {};

  Solution s;

  return 0;
}
