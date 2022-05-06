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
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) {
      return false;
    }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    for (int i = 0; i < (int)s.size(); ++i) {
      if (s[i] != t[i]) {
        return false;
      }
    }

    return true;
  }
  bool isAnagram_map(string s, string t) {
    if (s.size() != t.size()) {
      return false;
    }
    unordered_map<char, int> counts;
    for (int i = 0; i < (int)s.size(); ++i) {
      counts[s[i]]++;
      counts[t[i]]--;
    }

    for (auto count: counts){
      if (count.second != 0) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  std::vector<int> v = {};

  Solution s;

  return 0;
}
